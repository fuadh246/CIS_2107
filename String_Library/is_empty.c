//
// Created by Fuad Hassan on 4/24/23.
//
#include <stdio.h>
int  is_empty(char *s){
    if (s == NULL) {
        return 1;
    }
    while (*s != '\0'){
        if(*s != ' '){
            return 0;
        }
        s++;
    }
    return 1;
}