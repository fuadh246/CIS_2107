//
// Created by Fuad Hassan on 4/28/23.
//
#include <stdio.h>
#include <stdlib.h>
char **str_chop_all(char *s, char c){
    if(s==NULL){
        return NULL;
    }
    int words_count=1;
    for (int i = 0; i < s[i]!='\0'; i++) {
        if(s[i]==c){
            words_count++;
        }
    }
    char** list = (char**) malloc((words_count + 1) * sizeof(char*));
    if (list == NULL) {
        return NULL;
    }
    int list_start = 0;
    int list_end = 0;
    int list_index = 0;
    while (s[list_end]!='\0'){
        while (s[list_end] != c && s[list_end] != '\0') {
            list_end++;
        }
        int word_len = list_end-list_start;
        char *word = (char*) malloc((word_len+1) * sizeof(char));
        if (word == NULL) {
            // free previously allocated memory
            for (int i = 0; i < list_index; i++) {
                free(list[i]);
            }
            free(list);
            return NULL;
        }
        for (int i = 0; i < word_len; ++i) {
            word[i] = s[list_start + i];
        }
        word[word_len] = '\0';
        list[list_index] = word;
        list_start = list_end + 1;
        list_end = list_start;
        list_index++;
    }
    list[words_count] = NULL;
    return list;
}