//
// Created by Fuad Hassan on 4/26/23.
//
#include <stdio.h>
#include "find.c"

char *ptr_to(char *h, char *n) {
    int index = find(h, n);
    if (index == -1) {
        return NULL;
    }
    return h + index;
}