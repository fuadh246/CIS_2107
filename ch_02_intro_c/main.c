//
// Created by Fuad Hassan on 1/30/23.
//
#include <stdio.h>
#include <stdlib.h>
int sumEvenNumbers(unsigned int array[],unsigned int size);
int main () {
    printf("Start of the program....\n");
    unsigned int array[10]={1,2,3,4,5,6,7,8,9,10};
    int sum = sumEvenNumbers(array,10);
    printf("%d",sum);
    return(0);
}
int sumEvenNumbers(unsigned int array[],unsigned int size){
    int eSUM=0;
    for(unsigned int i=0; i<size;i++){
        if(array[i]%2==0){
            eSUM+=array[i];
        }
    }
    return eSUM;
}