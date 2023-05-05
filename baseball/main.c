#include <stdio.h>
/*
 * 12 HOOOWSHHOOHPWWHO
4 OSOHHHWWOHOHOOO
7 HOWOOWOSHOPHWOWOOHOSP
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int count = 0;
    int playersNum[3]={12, 4,  7};
    char playersScore[3][120]={"HOOOWSHHOOHPWWHO", "OSOHHHWWOHOHOOO","HOWOOWOSHOPHWOWOOHOSP"};
//    int playersNum[3]={0};
//    char *playersScore[3][120]={NULL};
//
//    FILE *file = fopen("/Users/fuadhassan/Library/CloudStorage/OneDrive-TempleUniversity/CIS_2107/baseball/data.txt","r");
//    if(file == NULL){
//        perror("data file failed to open");
//        exit(1);
//    }
//    while(count<3 && fscanf(file, "%d %s", &playersNum[count], playersScore[count]) != EOF) {
//        count++;
//    }
//    fclose(file);


    for(int i = 0; i < 3; i++) {
        int H=0;
        for(int j = 0; j < strlen(playersScore[i]); j++) {
            if(playersScore[i][j]=='H'){
                H++;
            }
        }

        double ave = ((double )H/ (double )strlen(playersScore[i]));
        printf("\nPlayer %d's ave is %.2lf", playersNum[i],ave);
        printf("\n");
    }
    return 0;
}

