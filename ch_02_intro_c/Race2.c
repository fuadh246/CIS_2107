//
// Created by Fuad Hassan on 3/16/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#define RED "\e[0;31m"
#define BLUE "\e[0;34m"
#define RESET "\x1b[0m"
#define START 1
#define END 70
#define RAND_MIN 1
#define RAND_MAX 10
unsigned short getStep();
void hareMove(unsigned int *harePosition);
void tortoiseMove(unsigned int *tortoisePosition);
void printGame(unsigned int harePosition, unsigned int tortoisePosition);
int main(void){
    srand((unsigned)time(NULL));
    unsigned int harePosition=1;
    unsigned int tortoisePosition=1;
    while (harePosition<10 && tortoisePosition<10){
//        sleep(1);
        tortoiseMove(&tortoisePosition);
//        printf("tortoisePosition -> %u\n",tortoisePosition);
        hareMove(&harePosition);
//        printf("harePosition -> %u\n",harePosition);
        printGame(harePosition,tortoisePosition);
    }
    return 0;
}
unsigned short getStep(){
    return rand() % (RAND_MAX)+ RAND_MIN;
}
void hareMove(unsigned int *harePosition){
    unsigned short step=getStep();
    if (step<=2){
        return;
    } else if (step<=4){
        *harePosition+=9;
    } else if (step<=5){
        *harePosition = (*harePosition<=12)?1:(*harePosition-=12);
    } else if (step<=8){
        *harePosition +=1;
    } else {
        *harePosition = (*harePosition=1)?1:(*harePosition-=1);
    }

}
void tortoiseMove(unsigned int *tortoisePosition){
    unsigned short step=getStep();
    if(step<=5){
        *tortoisePosition+= 3;
    } else if (step<=7){
        *tortoisePosition = (*tortoisePosition<=6)?1:(*tortoisePosition-=6);
    }
    else{*tortoisePosition+=1;
    }
}

void printGame(unsigned int harePosition, unsigned int tortoisePosition){
    unsigned int diff = abs(harePosition-tortoisePosition);
    if(diff==0){
        printf("OUCH!!!");
        return;
    }
}