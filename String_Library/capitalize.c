//
// Created by Fuad Hassan on 4/24/23.
//
#include <stdio.h>
void capitalize(char *s){
    char *sPtr = s;
    while (*sPtr != '\0'){
        if(sPtr == s || *(sPtr-1) == ' '){
            if(*sPtr >= 'a' && *sPtr <= 'z'){
                *sPtr -= 'a' - 'A';
            }
        }
        else {
            if (*sPtr >= 'A' && *sPtr <= 'Z') {
                *sPtr += 'a' - 'A';
            }
        }
        sPtr++;
    }
}