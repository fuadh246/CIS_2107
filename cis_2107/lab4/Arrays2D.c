//
// name: Fuad Hassan
// date: 02/21/2023
// course: CIS 2107
// homework number: 5 Arrays2D
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RED "\e[0;31m"
#define BLUE "\e[0;34m"
#define RESET "\x1b[0m"
#define RAND_MIN 0
#define RAND_MAX 100

void displayOutputs(int row,int col, int array[][col]);
int maxF(int row,int col,int array[][col]);
int rowSum(int row,int col, int array[][col]);
int columnSum(int row,int col,int array[][col]);
int isSquare(int row, int col);
int main(){
    int row=0,col=0;
    srand((unsigned)time(NULL));
    puts("Let's create a 2Dim array!\n");
    printf("\t%s", "How many rows? ");
    scanf("%d", &row);
    printf("\t%s", "How many cols? ");
    scanf("%d", &col);
    puts("");
    int array[row][col];
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("\tenter [%d][%d]:", i, j);
            scanf("%d", &array[i][j]);
        }
    }
    puts("");

    printf("The MAX value is: %d\n", maxF(row,col,array));
    for (int i = 0; i < row; i++) {
        printf("Sum of row %d = %d\n",i, rowSum(i,col,array));
    }
    puts("");

    for (int i = 0; i < col; ++i) {
        printf("Sum of col %d = %d\n",i, columnSum(row, i,array));
    }
    puts("");

    isSquare(row,col)? puts("This is a square array"): puts("This is not a square array.");
    puts("");
    puts("Here is your 2Dim array:");
    displayOutputs(row, col, array);
    return 0;
}
void displayOutputs(int row,int col, int array[][col]){
    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < col; j++) {
            printf("%5d", array[i][j]);
        }
        puts("");
    }
}
int maxF(int row,int col,int array[][col]){
    int max = 0;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
        if(max<array[i][j])
            max=array[i][j];
        }
    }
    return max;
}
int rowSum(int row,int col, int array[][col]) {
    int sum = 0;
    for (int i = 0; i < col; i++) {
        sum += array[row][i];
    }
    return sum;
}
int columnSum(int row,int col,int array[][col]){
    int sum = 0;
    for(int i=0; i<row;i++){
        sum+=array[i][col];
    }
    return sum;
}
int isSquare(int row, int col){
    return row == col;
}
