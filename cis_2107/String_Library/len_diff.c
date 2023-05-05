//
// Created by Fuad Hassan on 4/20/23.
//
#include <stdio.h>
int len_diff(char *s1, char *s2){
    int len_of_s1=0;
    int len_of_s2=0;
    while (*s1!='\0'){
        len_of_s1++;
        s1++;
    }
    while (*s2!='\0'){
        len_of_s2++;
        s2++;
    }
    return len_of_s1-len_of_s2;
}