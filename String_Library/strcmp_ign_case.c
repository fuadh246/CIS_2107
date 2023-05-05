//
// Created by Fuad Hassan on 4/24/23.
//

#include <stdio.h>
//Compares s1 and s2 ignoring case. Returns a positive number if s1 would appear after s2 in the dictionary, a
//negative number if it would appear before s2, or 0 if the two are equal.
int strcmp_ign_case(char *s1,char *s2){
    while (*s1!='\0' && *s2!='\0'){
        if(*s1 >= 'A' && *s1 <= 'Z'){
            *s1+=32;
        }
        if(*s2 >= 'A' && *s2 <= 'Z'){
            *s2+=32;
        }
        if (*s1 != *s2) {
            return (*s1 > *s2) ? 1 : -1;
        }
        s1++;
        s2++;
    }
    if(*s1 == '\0' && *s2 == '\0'){
        return 0;
    } else if(*s1 == '\0'){
        return -1;
    } else{
        return 1;
    }
}