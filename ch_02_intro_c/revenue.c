//
// Created by Fuad Hassan on 1/31/23.
//
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define BLUE "\e[0;34m"
#define RESET "\x1b[0m"

int check_input(double x);
double discount_rate_(double quantity);
double total_amount(double price, double quantity, double *cost, double *discount_rate, double *discount_amount);
void toString(double price, double quantity, double cost,double discount_rate, double discount_amount, double total);
int main(){
    puts(BLUE"Welcome to \"Temple\" store "RESET);
    double price=0;
    double quantity=0;
    double cost, discount_rate, discount_amount;
    printf("\tEnter item price: ");
    scanf("%lf",&price);
    if(check_input(price)==0){
        puts("\tThis is not a valid item price. \n\tPlease run the program again");
        puts(BLUE"Thank You for using \"Temple\" store "RESET);
        exit(1);
    }
    printf("\tEnter quantity: ");
    scanf("%lf",&quantity);
    if(check_input(quantity)==0){
        puts("\tThis is not a valid quantity order. \n\tPlease run the program again");
        puts(BLUE "Thank You for using \"Temple\" store " RESET);
        exit(1);
    }
    double total = total_amount(price,quantity,&cost,&discount_rate,&discount_amount);
    toString(price,quantity,cost,discount_rate,discount_amount,total);
    puts(BLUE "Thank You for using \"Temple\" store " RESET);
    return 0;
}
int check_input(double x){
    double decimels,num;
    decimels = modf(x,&num);
    if(decimels>0 && num>=0) {
        return 0;
    }else if(x<0){
        return 0;
    }
    return 1;
}
double discount_rate_(double quantity){
    if(quantity>0 && quantity<=49){
        return 0;
    }else if(quantity>=50 && quantity<=99){
        return 0.10;
    }else if(quantity>=100 && quantity<=149){
        return 0.15;
    }
    else{
        return .25;
    }
}
double total_amount(double price, double quantity, double *cost, double *discount_rate, double *discount_amount){
    *cost = quantity*price;
    *discount_rate= discount_rate_(quantity);
    *discount_amount = *cost * *discount_rate;
    return *cost-*discount_amount;
}

void toString(double price, double quantity, double cost,double discount_rate, double discount_amount, double total){
    printf("\tThe item price is: %.2f\n",price);
    printf("\tThe order is: %d\n",(int) quantity);
    printf("\tThe cost is: %.2f\n",cost);
    printf("\tThe discount is: %.2f\n",discount_rate*100);
    printf("\tThe discount amount is: %.2f\n",discount_amount);
    printf("\tThe total is: %.2f\n",total);
}
