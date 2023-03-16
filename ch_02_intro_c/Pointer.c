//
// Created by Fuad Hassan on 3/15/23.
//
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <stddef.h>
void cubeByreference(int *nPrt);
void convertToUpper(char *sPrt);
int main(void){
    int number=5;
    printf("%d\n",number);
    cubeByreference(&number);
    printf("%d\n",number);

    char string[] = "cHaRaCters and $32.98";
    printf("The string before conversion is: %s", string);
    convertToUpper(string);
    printf("\nThe string after conversion is: %s\n", string);

    return 0;
}
void cubeByreference(int *nPrt){
    *nPrt = *nPrt * *nPrt * *nPrt;
}
void convertToUpper(char *sPrt){
    while (*sPrt != '\0'){
        *sPrt = toupper(*sPrt);
        ++sPrt;
    }
}