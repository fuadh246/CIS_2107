//
// Created by Fuad Hassan on 3/26/23.
//
#include <stdio.h>
#include "struct.h"
int main(){

    struct student Fuad={1,"Fuad Hassan", 95.3};
    struct student Afrin={2,"Afrin Apon", 99.3};
    printf("\n%s",Fuad.name);
    struct student students[5]={Fuad, Afrin};

    printf("\n%s %s",students->name,students[1].name);

    return 0;
}