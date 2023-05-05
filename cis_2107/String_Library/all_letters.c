//
// Created by Fuad Hassan on 4/20/23.
//
#include <stdio.h>

int all_letters(char *s) {
    while (*s != '\0') {
        if ((*s < 'A' || *s > 'Z') && (*s < 'a' || *s > 'z') && (*s != ' ')) {
            return 0;
        }
        s++;
    }
    return 1;
}