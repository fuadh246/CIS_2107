//CIS2017 Lab7: Race
//The purpose of this program is to simulate and display the race between the tortoise and the hare using a random number
//generator and preset move types. The animal positions are accessed and modified using pointers, and the display is
//controlled using the sleep() function. Sometimes it takes a while due to slippage.


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define INT_MIN 1
#define INT_MAX 10

int randomNumberGenerator();
void tortMove(int *tPtr);
void hareMove(int *hPtr);
void printRace(int hPos,int tPos);
int min(int hMin, int tMin);
void printNSpaces(int n);

int main(){
    srand((unsigned)time(NULL));

    int hPos = 1;						//hare start position is 1, cannot slip past 1
    int tPos = 1;						//tortoise start position is 1, cannot slip past 1

    puts("\tON YOUR MARK, GET SET");
    puts("\tBANG               !!!!");	//the spacing is modeled after the sample
    puts("\tAND THEY'RE OFF    !!!!");	//the spacing is modeled after the sample

    while(hPos != 70 && tPos!=70){
        sleep(1);						//slows down the race
        hareMove(&hPos);
        tortMove(&tPos);

        printRace(hPos,tPos);
        puts("");
    }
    if(tPos >= hPos){
        puts("TORTOISE WINS!!! YAY!!!");
    }
    else{
        puts("Hare wins. Yuch.");
    }

}

//Finds minimum of hare or tortoise position to decide which position to print first
int min(int hMin, int tMin){
    if(hMin<tMin){
        return hMin;
    }
    return tMin;
}

void printNSpaces(int n){
    for(int i = 0; i < n; i++){
        printf(" ");
    }
}

//Prints the position of the H and T
void printRace(int hPos,int tPos){
    int diff = abs(hPos-tPos);
    if(diff==0){
        printf("OUCH!!!");
        return;
    }
    char losing = (min(hPos,tPos) == hPos) ? 'H' : 'T';
    char winning = (losing == 'H') ? 'T' : 'H';
    printNSpaces(min(hPos,tPos)-1);
    printf("%c",losing);
    printNSpaces(min(hPos,tPos)+diff-1);
    printf("%c",winning);
}

//Controls the tortoise movement
void tortMove(int *tPtr){
    unsigned short step=randomNumberGenerator();
    if(step<=5){
        *tPtr+= 3;
    } else if (step<=7){
        *tPtr = (*tPtr<=6)?1:(*tPtr-=6);
    }
    else{*tPtr+=1;
    }
}

//Controls the hare movement
void hareMove(int *hPtr){
    unsigned short step=randomNumberGenerator();
    if (step<=2){
        return;
    } else if (step<=4){
        *hPtr+=9;
    } else if (step<=5){
        *hPtr = (*hPtr<=12)?1:(*hPtr-=12);
    } else if (step<=8){
        *hPtr +=1;
    } else {
        *hPtr = (*hPtr=1)?1:(*hPtr-=1);
    }
}

//Generates random number from 1-10
int randomNumberGenerator(){
    return rand() % (INT_MAX)+ INT_MIN;
}
