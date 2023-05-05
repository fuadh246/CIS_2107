//
// Created by Fuad Hassan on 4/20/23.
//
#include <stdio.h>
int find(char *h, char *n){
    int count=0;
    for (;*h!='\0';h++) {
        count++;
        if(*h==*n){
            return count;
        }
    }
    return -1;
}
