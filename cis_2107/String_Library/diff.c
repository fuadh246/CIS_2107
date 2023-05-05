//
// Created by Fuad Hassan on 4/20/23.
//
#include <stdio.h>

int diff(char *s1, char *s2) {
    int count = 0;
    while (*s1 != '\0' && *s2 != '\0') {
        if (*s1 != *s2) {
            count++;
        }
        s1++;
        s2++;
    }
    while (*s1 != '\0') {
        count++;
        s1++;
    }
    while (*s2 != '\0') {
        count++;
        s2++;
    }
    return count;
}
