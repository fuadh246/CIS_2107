//
// Created by Fuad Hassan on 4/20/23.
//
#include <stdio.h>
void shorten(char *s, int new_len){
    int len_of_s = 0;
    char *sPtr = s;
    while (*sPtr != '\0') {
        len_of_s++;
        sPtr++;
    }
    if (len_of_s > new_len) {
        *(s + new_len) = '\0';
    }
}