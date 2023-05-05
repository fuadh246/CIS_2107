//
// Created by Fuad Hassan on 4/20/23.
//
#include <stdio.h>

void rm_right_space(char *s){
    char *sPtr=s;
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