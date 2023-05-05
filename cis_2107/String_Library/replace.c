//
// Created by Fuad Hassan on 4/25/23.
//
#include <stdio.h>
#include <stdlib.h>
char *replace(char *s, char *pat, char *rep){
    int len_of_s=0;
    while (s[len_of_s]!='\0'){
        len_of_s++;
    }
    int len_of_pat=0;
    while (pat[len_of_pat]!='\0'){
        len_of_pat++;
    }
    int len_of_rep=0;
    while (rep[len_of_rep]!='\0'){
        len_of_rep++;
    }
    int i=0,j=0,occurrence=0;
    for (i = 0; i <= len_of_s - len_of_pat; i++) {
        for (j = 0; j < len_of_pat; j++) {
            if (s[i+j] != pat[j]) {
                break;
            }
        }
        if (j == len_of_pat) {
            occurrence++;
            i += len_of_pat - 1;
        }
    }
    int replaced_size = len_of_s + occurrence * (len_of_rep - len_of_pat);
    char *replaced=(char *) malloc(sizeof (char )*(replaced_size+1));
    if (replaced == NULL) {
        return NULL;
    }

    int s_index = 0;
    int replaced_index = 0;
    while (s_index < len_of_s) {
        int match = 1;
        for (i = 0; i < len_of_pat; i++) {
            if (s[s_index + i] != pat[i]) {
                match = 0;
                break;
            }
        }
        if (match) {
            for (i = 0; i < len_of_rep; i++) {
                replaced[replaced_index++] = rep[i];
            }
            s_index += len_of_pat;
        } else {
            replaced[replaced_index++] = s[s_index++];
        }
    }
    replaced[replaced_index] = '\0';

    return replaced;
}
