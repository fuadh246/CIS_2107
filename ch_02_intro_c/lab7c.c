//
// Created by Fuad Hassan on 3/2/23.
//

#include <stdio.h>
#include <stdlib.h>

//main functions
void printArray(int students, int exams, int grades[students][exams]);
void minimum(int students, int exams, int grades[students][exams]);
void maximum(int students, int exams, int grades[students][exams]);
void average(int students, int exams, int grades[students][exams]);

//helpers
int getUsrChoice(int rStart, int rEnd);
void print1DArr(size_t size, int arr[size]);
int findMinInArr(size_t size, int arr[size]);
int findMaxInArr(size_t size, int arr[size]);
double avgOfArr(size_t size, int arr[size]);

int main()
{
    int usrCh;
    //at this point choice is valid and corresponds to a function

    //getting user params
    unsigned students = 0, exams = 0;
    printf("\nEnter Number of Students: ");
    scanf("%u", &students);

    printf("Enter Number of Exams per Student: ");
    scanf("%u", &exams);

    //getting usr arr
    puts("Enter in the Student-Exam data");
    int grades[students][exams];

    puts("");

    for(size_t r = 0; r < students; r++){
        for(size_t c = 0; c < exams; c++){
            printf("Score for Student %lu Exam %lu: ", r, c);
            scanf("%d", (*(grades + r) + c)); //finds the address of the correct spot
        }
        puts("");
    }

    void (*processGrades[4])(int, int, int[][exams]) = {printArray, minimum, maximum, average};

    usrCh = getUsrChoice(0, 4);
    while(usrCh != 4){
        (*processGrades[usrCh])(students, exams, grades);
        usrCh = getUsrChoice(0, 4);
    }
}

//gets user choice over integer interval [rStart, rEnd]
int getUsrChoice(int rStart, int rEnd){
    int choice;
    puts("\nEnter a choice:");
    printf("\t%d Print the array of grades\n", 0);
    printf("\t%d Find the minimum grade\n", 1);
    printf("\t%d Find the maximum grade\n", 2);
    printf("\t%d Print the average on all the tests for each student\n", 3);
    printf("\t%d End Program\n", 4);

    printf("Your Choice: ");
    scanf("%d", &choice);

    //if the choice is invalid (out of bounds) force usr to pick again
    if(choice < rStart || choice > rEnd){
        return getUsrChoice(rStart, rEnd);
    }
    return choice;
}

void print1DArr(size_t size, int arr[size]){
    putc('[', stdout);
    for(size_t i = 0; i < size - 1; i++){
        printf("%3d, ", arr[i]); //print all elemnts but last
    }
    if(size > 0){ //ensure [size - 1] exists
        printf("%3d", arr[size - 1]); //print out last elment
    }
    putc(']', stdout);
}

void printArray(int students, int exams, int grades[students][exams]){
    for (size_t stu = 0; stu < students; stu++)
    {
        printf("\nStudent[%lu]: ", stu);
        print1DArr(exams, grades[stu]);
    }

}

//the three functions below find the min/max/avg of a 1d arr
int findMinInArr(size_t size, int arr[size]){
    if(size < 1){
        return -1;
    }
    int min = arr[0];
    for(size_t i = 0; i < size; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }

    return min;

}

int findMaxInArr(size_t size, int arr[size]){
    if(size < 1){
        return -1;
    }
    int max = arr[0];
    for(size_t i = 0; i < size; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }

    return max;

}

double avgOfArr(size_t size, int arr[size]){
    double sum = 0.0;

    for (size_t i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    return sum / size;
}


void minimum(int students, int exams, int grades[students][exams]){
    puts("\nMinimum Grades per each Student: ");
    for(size_t s = 0; s < students; s++){
        printf("\tStudent [%lu]: %3d\n", s, findMinInArr(exams, grades[s]));
    }
}
void maximum(int students, int exams, int grades[students][exams]){
    puts("\nMaximum Grades per each Student: ");
    for(size_t s = 0; s < students; s++){
        printf("\tStudent [%lu]: %3d\n", s, findMaxInArr(exams, grades[s]));
    }
}
void average(int students, int exams, int grades[students][exams]){
    puts("\nAverage Scores per Student: ");
    for(size_t s = 0; s < students; s++){
        printf("\tStudent [%lu]: %.2lf\n", s, avgOfArr(exams, grades[s]));
    }
}