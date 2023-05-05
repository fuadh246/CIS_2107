//
// Created by Fuad Hassan on 4/20/23.
//
#include <stdio.h>

int diff(char *s1, char *s2){
    int count=0;
    while (*s1!='\0'||*s2!='\0'){
        if(*s1!=*s2){
            count++;
            if (*s1 == '\0') {
                s2++;
            } else if (*s2 == '\0') {
                s1++;
            }
        }
        s1++;
        s2++;
    }
    return 0;
}