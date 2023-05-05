//
// Created by Fuad Hassan on 4/25/23.
//
#include <stdio.h>
#include <stdlib.h>
char *repeat(char *s, int x, char sep){
    if(s==NULL){
        return NULL;
    }
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    char *result = (char *) malloc((len * x) + (x - 1) * sizeof(char));
    if (result == NULL) {
        return NULL;
    }
    int i, j;
    for (i = 0; i < x; i++) {
        for (j = 0; s[j] != '\0'; j++) {
            result[(i * len) + j + i] = s[j];
            if (i != x - 1) {
                result[(i * len) + j + i + 1] = sep;
            }
        }
    }
    result[(len * x) + (x - 1)] = '\0';
    return result;
}