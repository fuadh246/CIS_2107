//
// Created by Fuad Hassan on 4/28/23.
//
#include <stdio.h>
char *str_zip(char *s1, char *s2) {
    int len_of_s1 = 0, len_of_s2 = 0;

    while (*s1 != '\0') {
        len_of_s1++;
        s1++;
    }

    while (*s2 != '\0') {
        len_of_s2++;
        s2++;
    }

    char *result = (char *) malloc((len_of_s1 + len_of_s2 + 1) * sizeof(char));
    if (result == NULL) {
        return NULL;
    }

    s1 -= len_of_s1;
    s2 -= len_of_s2;

    char *resultPtr = result;
    while (*s1 != '\0' || *s2 != '\0') {
        if (*s1 != '\0') {
            *resultPtr++ = *s1++;
        }
        if (*s2 != '\0') {
            *resultPtr++ = *s2++;
        }
    }

    *resultPtr = '\0';x

    return result;
}