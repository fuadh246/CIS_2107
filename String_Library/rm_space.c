//
// Created by Fuad Hassan on 4/20/23.
//
#include <stdio.h>

void rm_space(char *s){
    char *sPtr = s;
    char *left_removed=s;
    while (*sPtr == ' ' || *sPtr == '\t' || *sPtr == '\n'){
        sPtr++;
    }
    if(sPtr!=s){
        while (*sPtr!='\0'){
            *left_removed++ = *sPtr++;
        }
        *left_removed = '\0';
    }
    sPtr=s;
    while (*sPtr!='\0'){
        sPtr++;
    }
    if(sPtr!=s){
        sPtr--;
        while (*sPtr == ' ' || *sPtr == '\t' || *sPtr == '\n'){
            *sPtr='\0';
            sPtr--;
        }
    }
}
