//
// Created by Fuad Hassan on 4/28/23.
//
#include <stdio.h>
#include <stdlib.h>
char *str_connect(char **strs, int n, char c){
    int len = 0;
    for (int i = 0; i < n; ++i) {
        char *s = strs[i];
        while (*s!='\0'){
            len++;
            s++;
        }if (i < n - 1) {
            len++; // Add the separator length
        }
    }
    char *result = (char*) malloc(len+1);
    if (result == NULL) {
        return NULL;
    }
    char *resultPtr=result;
    for (int i = 0; i < n; ++i) {
        char *s = strs[i];
        while (*s!='\0'){
            *resultPtr = *s;
            resultPtr++;
            s++;

        }if (i < n - 1) {
            *resultPtr=c;
            resultPtr++;
        }
    }
    *resultPtr = '\0';
    return result;
}