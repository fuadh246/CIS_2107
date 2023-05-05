//
// Created by Fuad Hassan on 3/24/23.
//
#include <stdio.h>
#include<string.h>
#include <stdbool.h>
#include <ctype.h>

void upperCase(char *str){
    while (*str != '\0'){
        *str = toupper(*str);
        ++str;
    }
}

int main(){
    int x=5;
    int *ptr;
    ptr = &x;

    *ptr = *ptr *3;
    printf("%c\n",x);
    printf("%p\n",ptr);
    printf("%p\n",*ptr);
    printf("%p\n",&ptr);


        int a=10;
        int b=20;
        int *p=&b;
        int *q=p;
        (*p)++;
        q++;

    int grades[5] = {95, 90, 100, 82, 92};
    int *iPtr = grades;
    printf(" %d\n %d\n %p\n %p\n",*iPtr, 0[grades], grades, iPtr);

    int y, *z;
    y = 4;
    z = &y;
    y = *z + 9;
    printf("%d\n",y);

    int age = 5, tom = 0, jerry = 0;
    int* aPtr = &age;
    tom = (*aPtr)++; // post associativity is left to right
    printf("\n%d", age); // by the way post is higher than pre
    printf("\n%d", tom);


    char *bPtr = "baby shark";
    char songTitle[6]; // Question: try 5
    strcpy(songTitle, "dance");
    printf("\n%s %s",bPtr, songTitle);

    bool Fuad = true;
    Fuad ? printf("\ntrue") : NULL;

    int repsonse[10]={1,2,3,2,2,3,1,2,3,4};
    int frec[5]={0};

    for (int i = 0; i < 10; i++) {
        frec[repsonse[i]]++;
    }
    for (int i = 1; i <= 5; i++) {
        printf("\n%d %d",i,frec[i]);
    }

    char name[] = "Fuad Hassan";
    printf("\n%s",name);
    upperCase(name);
    printf("\n%s",name);


    int array[5]={1,2,3,4,5,};
    int *pArray=array;

    int length = sizeof(array) / sizeof(int);
    printf("\n\t%d",sizeof(array));
    printf("\n\t%d",sizeof (int));

    puts("\narray loop");
    for (int i = 0; i < length; i++) {
        printf("\n\t%d",array[i]);
    }
    puts("\npointer loop");
    for (int i = 0; i < length; ++i) {
        printf("\n\t%d",pArray[i]);
    }

    enum week {Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};
    enum week today;
    today = Wednesday;
    printf("\nDay %d",today+1);
    return 0;
}