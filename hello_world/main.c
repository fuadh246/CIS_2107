#include <stdio.h>

 int sum(int num1,int num2);

int main() {
    printf("Hello, World!\n");
    int x = sum(5,5);
    printf(" %d",x);
    return 0;
}
int sum(int num1,int num2){
    return num1+num2;
}
