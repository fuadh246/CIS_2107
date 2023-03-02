/* 
Name: 
Date:
Course: CSI2107 
HW#: Lab 05: ““Arrays of Pointers to Functions” 

Objective: To design and implement array of function pointer. 

The purpose of this program is to modify existing code related to examslecting 
grades for individual students in a 2D matrix and determining the minimum, maximum, and each average. 

// Each of the functions has also been modified to allow for a
// menu-driven interface. This interface is an array of pointers to the functions.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RAND_MIN 1
#define RAND_MAX 100
void printArray(int students, int exams, int grades[students][exams]);
void minimum(int students, int exams, int grades[students][exams]);
void maximum(int students, int exams, int grades[students][exams]);
void average(int students, int exams, int grades[students][exams]);

int main(void)
{
    srand((unsigned)time(NULL));
    int students=3,exams=3;
    int grades[students][exams];
    for (int student = 0; student < students;student++) {
        for (int exam = 0; exam < exams; exam++) {
            grades[student][exam]=rand()%(RAND_MAX+1)+RAND_MIN;
        }
    }


    printArray(students,exams,grades);
    minimum(students,exams,grades);
    maximum(students,exams,grades);
    average(students,exams,grades);
    return 0;
}

void printArray(int students, int exams, int grades[students][exams]){
    for (size_t student = 0; student < students; student++) {
        for (size_t exam = 0; exam < exams; exam++) {
            printf("%5d", grades[student][exam]);
        }
        puts("");
    }
}
void minimum(int students, int exams, int grades[students][exams]){
    int min=grades[0][0];
    for (int student = 0; student < students; ++student) {
        for (int exam = 0; exam < exams; exam++) {
            if(min>grades[student][exam])
                min=grades[student][exam];
        }
    }
    printf("MIN= %d\n",min);

}
void maximum(int students, int exams, int grades[students][exams]){
    int max=0;
    for (int student = 0; student < students; ++student) {
        for (int exam = 0; exam < exams; exam++) {
            if(max<grades[student][exam])
                max=grades[student][exam];
        }
    }
    printf("MAX= %d\n",max);
}
void average(int students, int exams, int grades[students][exams]){
    int sum=0;
    for (int student = 0; student < students; student++) {
        for (int exam=0; exam<exams; exam++){
            sum+=grades[student][exam];
        }
        printf("Average of student %d is %.2lf\n", student, (double)sum/exams);
        sum =0;
    }
}