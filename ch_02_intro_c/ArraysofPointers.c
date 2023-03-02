/* 
Name: Fuad Hassan
Date: 03/02/2023
Course: CSI2107 
HW#: Lab 05: “Arrays of Pointers to Functions”

Objective: To design and implement array of function pointer. 

The purpose of this program is to modify existing code related to examslecting 
grades for individual students in a 2D matrix and determining the minimum, maximum, and each average. 

// Each of the functions has also been modified to allow for a
// menu-driven interface. This interface is an array of pointers to the functions.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int students, int exams, int grades[students][exams]);
void minimum(int students, int exams, int grades[students][exams]);
void  maximum(int students, int exams, int grades[students][exams]);
void average(int students, int exams, int grades[students][exams]);

int minValue(int students, int exams, int grades[students][exams]);
int maxValue(int students, int exams, int grades[students][exams]);
int getChoice();
int main(void)
{
    srand((unsigned)time(NULL));
    int students=0,exams=0;
    printf("Enter Number of Students: ");
    scanf("%d", &students);

    printf("Enter Number of Exams per Student: ");
    scanf("%d", &exams);
    puts("");
    int grades[students][exams];

    for (int student = 0; student < students;student++) {
        for (int exam = 0; exam < exams; exam++) {
            printf("Student [%d] exam [%d] score: ",student,exam);
            scanf("%d",&grades[student][exam]);
        }
    }
    void (*processGrades[4])(int,int, int[students][exams])={printArray,minimum,maximum,average};
    size_t choice=getChoice();
    while (choice!=4){
        (*processGrades[choice])(students,exams,grades);
        choice=getChoice();
    }
    return 0;
}
int getChoice(){
    size_t choice;
    puts("Enter a choice:");
    puts("\t0 Print the array of grades");
    puts("\t1 Find the minimum grade");
    puts("\t2 Find the maximum grade");
    puts("\t3 Print the average on all the tests for each student");
    puts("\t4 End Program\n");
        printf("Your Choice: ");
        scanf("%d", &choice);
    return choice;
}

void  printArray(int students, int exams, int grades[students][exams]){
    for (size_t student = 0; student < students; student++) {
        printf("Student [%d] :[",student);
        for (size_t exam = 0; exam < exams; exam++) {
            printf(" %2d,", grades[student][exam]);
        }
        printf("]\n");
    }
    puts("");
}
void  minimum(int students, int exams, int grades[students][exams]){
    for (int student = 0; student < students; ++student) {
        printf("\tStudent [%d]: %3d\n", student, minValue(student,exams,grades));
    }
    puts("");
}
int minValue(int students, int exams, int grades[students][exams]){
    int min=grades[0][0];
    for (int exam = 0; exam < exams; exam++) {
        if(min>grades[students][exam])
            min=grades[students][exam];
    }
    return min;
}

void  maximum(int students, int exams, int grades[students][exams]){
    for (int student = 0; student < students; ++student) {
        printf("\tStudent [%d]: %3d\n", student, maxValue(student,exams,grades));
    }
    puts("");
}
int maxValue(int students, int exams, int grades[students][exams]){
    int max=grades[0][0];
    for (int exam = 0; exam < exams; exam++) {
        if(max<grades[students][exam])
            max=grades[students][exam];
    }
    return max;
}
void  average(int students, int exams, int grades[students][exams]){
    int sum=0;
    for (int student = 0; student < students; student++) {
        for (int exam=0; exam<exams; exam++){
            sum+=grades[student][exam];
        }
        printf("Average of student [%d] is %.2lf\n", student, (double)sum/exams);
        sum=0;
    }
    puts("");
}