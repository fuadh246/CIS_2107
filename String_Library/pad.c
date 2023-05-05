//
// Created by Fuad Hassan on 4/24/23.
//
#include <stdio.h>
#include <stdlib.h>
char *pad(char *s, int d){
    if (s == NULL) {
        return NULL;
    }
    int len = 0;
    while (s[len]!='\0'){
        len++;
    }
    unsigned int paded_size=(((len + d - 1) / d) * d);
    char *paded_s=(char *) malloc( paded_size+ 1);
    if (paded_s == NULL) {
        return NULL;
    }
    int i = 0;
    for (; i < len; i++) {
        paded_s[i] = s[i];
    }
    for (; i < paded_size; i++) {
        paded_s[i] = ' ';
    }
    paded_s[paded_size] = '\0';
    return paded_s;
}