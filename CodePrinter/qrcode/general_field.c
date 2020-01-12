/* general_field.c - Handles general field compaction (GS1 DataBar and composites) */

/*
    libzint - the open source barcode library
    Copyright (C) 2008-2019 Robin Stuart <rstuart114@gmail.com>

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions
    are met:

    1. Redistributions of source code must retain the above copyright
       notice, this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.
    3. Neither the name of the project nor the names of its contributors
       may be used to endorse or promote products derived from this software
       without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
    ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
    FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
    DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
    OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
    HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
    LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
    OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
    SUCH DAMAGE.
 */
/* vim: set ts=4 sw=4 et : */

#include <string.h>
#include "common.h"
#include "general_field.h"

static char alphanum_puncs[] = "*,-./";
static char isoiec_puncs[] = "!\"%&'()*+,-./:;<=>?_ ";

/* Returns type of char at `i`. FNC1 counted as NUMERIC. Returns 0 if invalid char */
static int general_field_type(char* general_field, int i) {
    if (general_field[i] == '[' || (general_field[i] >= '0' && general_field[i] <= '9')) {
        return NUMERIC;
    }
    if ((general_field[i] >= 'A' && general_field[i] <= 'Z') || strchr(alphanum_puncs, general_field[i])) {
        return ALPHA;
    }
    if ((general_field[i] >= 'a' && general_field[i] <= 'z') || strchr(isoiec_puncs, general_field[i])) {
        return ISOIEC;
    }
    return 0;
}

/* Returns true if next (including `i`) `num` chars of type `type`, or if given (non-zero), `type2` */
static int general_field_next(char* general_field, int i, int general_field_len, int num, int type, int type2) {
    if (i + num > general_field_len) {
        return 0;
    }
    for (; i < general_field_len && num; i++, num--) {
        int type_i = general_field_type(general_field, i);
        if ((type_i != type && !type2) || (type_i != type && type_i != type2)) {
            return 0;
        }
    }
    return num == 0;
}

/* Returns true if next (including `i`) `num` up to `max_num` chars of type `type` and occur at end */
static int general_field_next_terminate(char* general_field, int i, int general_field_len, int num, int max_num, int type) {
    if (i + max_num < general_field_len) {
        return 0;
    }
    for (; i < general_field_len; i++, num--) {
        if (general_field_type(general_field, i) != type) {
            return 0;
        }
    }
    return i == general_field_len && num <= 0;
}

/* Returns true if none of the next (including `i`) `num` chars (or end occurs) of type `type` */
static int general_field_next_none(char* general_field, int i, int general_field_len, int num, int type) {
    for (; i < general_field_len && num; i++, num--) {
        if (general_field_type(general_field, i) == type) {
            return 0;
        }
    }
    return num == 0 || i == general_field_len;
}

/* Attempts to apply encoding rules from sections 7.2.5.5.1 to 7.2.5.5.3
 * of ISO/IEC 24724:2011 (same as sections 5.4.1 to 5.4.3 of ISO/IEC 24723:2010) */
INTERNAL int general_field_encode(char* general_field, int* p_mode, int* p_last_digit, char binary_string[]) {
    int i, d1, d2;
    int mode = *p_mode;
    int last_digit = 0; /* Set to odd remaining digit at end if any */
    int general_field_len = strlen(general_field);

    for (i = 0; i < general_field_len; ) {
        int type = general_field_type(general_field, i);
        if (!type) {
            return 0;
        }
        switch (mode) {
            case NUMERIC:
                if (i < general_field_len - 1) { /* If at least 2 characters remain */
                    if (type != NUMERIC || general_field_type(general_field, i + 1) != NUMERIC) { /* 7.2.5.5.1/5.4.1 a) */
                        strcat(binary_string, "0000"); /* Alphanumeric latch */
                        mode = ALPHA;
                    } else {
                        d1 = general_field[i] == '[' ? 10 : ctoi(general_field[i]);
                        d2 = general_field[i + 1] == '[' ? 10 : ctoi(general_field[i + 1]);
                        bin_append((11 * d1) + d2 + 8, 7, binary_string);
                        i += 2;
                    }
                } else { /* If 1 character remains */
                    if (type != NUMERIC) { /* 7.2.5.5.1/5.4.1 b) */
                        strcat(binary_string, "0000"); /* Alphanumeric latch */
                        mode = ALPHA;
                    } else {
                        last_digit = general_field[i]; /* Ending with single digit. 7.2.5.5.1 c) and 5.4.1 c) dealt with separately outside this procedure */
                        i++;
                    }
                }
                break;
            case ALPHA:
                if (general_field[i] == '[') { /* 7.2.5.5.2/5.4.2 a) */
                    strcat(binary_string, "01111");
                    mode = NUMERIC;
                    i++;
                } else if (type == ISOIEC) { /* 7.2.5.5.2/5.4.2 b) */
                    strcat(binary_string, "00100"); /* ISO/IEC 646 latch */
                    mode = ISOIEC;
                } else if (general_field_next(general_field, i, general_field_len, 6, NUMERIC, 0)) { /* 7.2.5.5.2/5.4.2 c) */
                    strcat(binary_string, "000"); /* Numeric latch */
                    mode = NUMERIC;
                } else if (general_field_next_terminate(general_field, i, general_field_len, 4, 5 /*Can limit to 5 max due to above*/, NUMERIC)) { /* 7.2.5.5.2/5.4.2 d) */
                    strcat(binary_string, "000"); /* Numeric latch */
                    mode = NUMERIC;
                } else if ((general_field[i] >= '0') && (general_field[i] <= '9')) {
                    bin_append(general_field[i] - 43, 5, binary_string);
                    i++;
                } else if ((general_field[i] >= 'A') && (general_field[i] <= 'Z')) {
                    bin_append(general_field[i] - 33, 6, binary_string);
                    i++;
                } else {
                    bin_append(posn(alphanum_puncs, general_field[i]) + 58, 6, binary_string);
                    i++;
                }
                break;
            case ISOIEC:
                if (general_field[i] == '[') { /* 7.2.5.5.3/5.4.3 a) */
                    strcat(binary_string, "01111");
                    mode = NUMERIC;
                    i++;
                } else {
                    int next_10_not_isoiec = general_field_next_none(general_field, i, general_field_len, 10, ISOIEC);
                    if (next_10_not_isoiec && general_field_next(general_field, i, general_field_len, 4, NUMERIC, 0)) { /* 7.2.5.5.3/5.4.3 b) */
                        strcat(binary_string, "000"); /* Numeric latch */
                        mode = NUMERIC;
                    } else if (next_10_not_isoiec && general_field_next(general_field, i, general_field_len, 5, ALPHA, NUMERIC)) { /* 7.2.5.5.3/5.4.3 c) */
                        /* Note this rule can produce longer bitstreams if most of the alphanumerics are numeric */
                        strcat(binary_string, "00100"); /* Alphanumeric latch */
                        mode = ALPHA;
                    } else if ((general_field[i] >= '0') && (general_field[i] <= '9')) {
                        bin_append(general_field[i] - 43, 5, binary_string);
                        i++;
                    } else if ((general_field[i] >= 'A') && (general_field[i] <= 'Z')) {
                        bin_append(general_field[i] - 1, 7, binary_string);
                        i++;
                    } else if ((general_field[i] >= 'a') && (general_field[i] <= 'z')) {
                        bin_append(general_field[i] - 7, 7, binary_string);
                        i++;
                    } else {
                        bin_append(posn(isoiec_puncs, general_field[i]) + 232, 8, binary_string);
                        i++;
                    }
                }
                break;
        }
    }

    *p_mode = mode;
    *p_last_digit = last_digit;
    return 1;
}
