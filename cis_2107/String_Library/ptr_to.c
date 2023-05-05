//
// Created by Fuad Hassan on 4/26/23.
//
#include <stdio.h>

char *ptr_to(char *h, char *n) {
    while (*h != '\0') {
        if (*h == *n) {
            return h;
        }
        h++;
    }
    return NULL;
}