//
// Created by Fuad Hassan on 4/24/23.
//
#include <stdio.h>
#include <stdlib.h>
char *dedup(char *s){
    int len = 0;
    while (s[len]!='\0'){
        len++;
    }
    char *no_dup_s = (char*) malloc(len + 1);
    if (no_dup_s == NULL) {
        return NULL;
    }
    int freq[256]={0};
    int i = 0;
    int j = 0;
    while (s[i] != '\0') {
        if (freq[s[i]] == 0) { // if character is not a duplicate
            freq[ s[i]] = 1;
            no_dup_s[j] = s[i];
            j++;
        }
        i++;
    }
    no_dup_s[j]='\0';

    return no_dup_s;
}