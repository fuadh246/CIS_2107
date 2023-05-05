//
// Created by Fuad Hassan on 4/28/23.
//
#include <stdio.h>

void rm_empties(char** words) {
    int i=0,j=0;
    while (words[i]!=NULL){
        char *word=words[i];
        int len_of_word=0;
        while (*word!='\0'){
            len_of_word++;
            word++;
        }
        if(len_of_word>0){
            words[j] = words[i];
            j++;
        }
        i++;
    }
    words[j] = NULL;
}