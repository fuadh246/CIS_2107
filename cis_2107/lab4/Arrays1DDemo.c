//
// name: Fuad Hassan
// date: 02/12/2023
// course: CIS 2107
// homework number: 4
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RED "\e[0;31m"
#define BLUE "\e[0;34m"
#define RESET "\x1b[0m"
#define RAND_MIN 0
#define RAND_MAX 100
#define SIZE 40
void printArray(int array[], int size);
void fillArray(int array[], int size);
int handelIndexBound(short lowSelectedRange, short highSelectedRange);
int findWithRange(int array[], int size, short lowSelectedRange, short highSelectedRange);
void reverseArray(int array[], int size);
void reverseSelectedRangeWithinArray(int array[], int size,short startRange, short endRange);
void findSequence(int array[],int size);
int main(int argc, const char * argv[]){
    srand((unsigned)time(NULL));
    int array[SIZE];
    int array2[SIZE];
    int array3[SIZE];
    puts(BLUE"Array"RESET);
    fillArray(array,SIZE);
    printArray(array,SIZE);
    for (int i = 0; i <SIZE; ++i) {
        array2[i]=array[i];
        array3[i]=array[i];
    }

    short lowSelectedRange=0;
    short highSelectedRange=9;
    int x = findWithRange( array,SIZE,  lowSelectedRange, highSelectedRange);
    printf(BLUE"MAX from index "RED"%u"BLUE" to "RED"%u"BLUE" is: "RED"%d\n"RESET,lowSelectedRange,highSelectedRange,x);

    puts(BLUE"Reversed Array"RESET);
    reverseArray(array,SIZE);
    printArray(array,SIZE);
    puts(BLUE"Reverse Selected Range Within Array"RESET);
    reverseSelectedRangeWithinArray(array2,SIZE,15,25);

    printArray(array2,SIZE);

    findSequence(array3,SIZE);

    return 0;
}
/*
 * This code defines a function named printArray that takes an integer array and its size as inputs,
 * and prints the elements of the array to the console in a tabular format. Each element is printed
 * with a fixed width of 5 characters and a tab character is inserted before each element to provide
 * some spacing. A line break is added after every 10 elements.
 * */
void printArray(int array[], int size){
    for (unsigned int i = 0; i <size; i++) {
        printf("\t%5d",array[i]);
        if ((i + 1) % 10 == 0){
            puts("");
        }
    }
}
/*
 * fills the array with random numbers
 * */
void fillArray(int array[], int size){
    for(unsigned int i=0;i<size;i++){
        array[i]= rand()%(RAND_MAX+1)+RAND_MIN;
    }
}
/*
 *This code defines a function named fillArray that takes an integer array and its size as inputs,
 * and fills the array with random integer values. The rand function is used to generate random
 * numbers, and the values are scaled to fit within the range of RAND_MIN to RAND_MAX. The resulting
 * array can be used for testing or experimentation purposes.
 * */
int handelIndexBound(short lowSelectedRange, short highSelectedRange){
    if(highSelectedRange<lowSelectedRange){
        return -1;
    }else if(lowSelectedRange<0 || highSelectedRange>SIZE){
        return -1;
    }
    return 1;
}
/*
 * This code finds the maximum value within a selected range of indices in an integer array.
 * It returns the maximum value, or -1 if the selected range is out of bounds.
 * */
int findWithRange(int array[], int size, short lowSelectedRange, short highSelectedRange){
     int MAX=-1;
    if (handelIndexBound(lowSelectedRange,highSelectedRange)==1){
        for (unsigned i=lowSelectedRange;i<=highSelectedRange;i++){
            if(MAX<array[i]){
                MAX=array[i];
            }
        }
    } else{
        exit(0);
    }
    return MAX;
}
/*
 * This code reverses the order of elements in an integer array. It uses a while loop and two
 * index variables to swap the elements starting from the beginning and end of the array and
 * moving towards the center until the entire array is reversed.
 * */
void reverseArray(int array[], int size){
    int i=0;
    while (i<size){
        unsigned int temp = array[i];
        array[i]=array[size-1];
        array[size-1]=temp;
        i++;
        size--;
    }
}
/*
 * reverse the array from startRange and endRange range
 * */
void reverseSelectedRangeWithinArray(int array[], int size,short startRange, short endRange){
    if (handelIndexBound(startRange,endRange)==1){
        while (startRange<endRange){
            unsigned int temp = array[startRange];
            array[startRange]=array[endRange];
            array[endRange]=temp;
            startRange++;
            endRange--;
        }
    } else{
        puts(RED"INVALID index"RESET);
        exit(0);
    }
}
/*
 * looks for the Sequence input by user in the array and if it find it. it print the index of the element else print not found.
 * */
void findSequence(int array[],int size){
    unsigned int Tom,Jerry;
    printf(BLUE"Enter two numbers: "RESET);
    scanf("%d %d",&Tom,&Jerry);
    for (int i = 0; i < size; ++i) {
        if(array[i]==Tom && array[i+1]==Jerry){
            printf("sequence found at index ");
            printf(RED"%d\n"RESET,i);
            break;
        } else if(size-1==i){
            puts(RED"sequence not found"RESET);
            break;
        }
    }
}