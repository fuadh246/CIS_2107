//
// Created by Fuad Hassan on 4/25/23.
//
#include <stdio.h>
int ends_with_ignore_case(char *s, char *suff){
    if(*s >= 'A' && *s <= 'Z'){
        *s+=32;
    }
    if(*suff >= 'A' && *suff <= 'Z'){
        *suff+=32;
    }
    int len_of_s=0;
    while (s[len_of_s]!='\0'){
        len_of_s++;
    }
    int len_of_suff=0;

    while (suff[len_of_suff]!='\0'){
        len_of_suff++;
    }

    int i=len_of_s-len_of_suff;
    printf("%d\n",i);
    int j=0;
    for (;i<len_of_s;i++) {
        printf("%c == %c\n",s[i],suff[j]);
        if(s[i+1]!=suff[j]){
            return 0;
        }
    }
    return 1;
}