//
// Created by Fuad Hassan on 4/24/23.
//
#include <stdio.h>
/*
 * Modifies s so that it consists of only its last n characters. If n is ≥ the length of s, the original string is unmodified.
For example if we call take_last("Brubeck" 5), when the function finishes, the original string becomes "ubeck"
 * */

void take_last(char *s, int n) {
    int len = 0;
    char *sPtr = s;
    while (*sPtr != '\0') {
        len++;
        sPtr++;
    }
    if (n < len) {
        int start_from = len - n;
        char *temp=s + start_from;
        while (*temp!='\0'){
            *s=*temp;
            s++,temp++;
        }
        *s = '\0';
    }
}
