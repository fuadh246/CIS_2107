//
// Created by Fuad Hassan on 1/30/23.
//

#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define RED "\e[0;31m"
#define BLUE "\e[0;34m"
#define RESET "\x1b[0m"
int check_input(double x);
double net_pay(double Hourly_rate, double Weekly_time, double *Regular_pay,double *Overtime_pay);
void toString(double Employee_id, double Hourly_rate, double Weekly_time,
              double Net_pay, double Regular_pay,double Overtime_pay);


int main(int argc, char** argv){
    double Employee_id,Hourly_rate,Weekly_time, Regular_pay,Overtime_pay;
    puts(BLUE"Welcome to \"TEMPLE HUMAN RESOURCES\" "RESET);
    printf("Enter Employee Number: ");
    scanf("%lf",&Employee_id);
    if(check_input(Employee_id)==0){
        puts("\tThis is not a valid Employee Number. \n\tPlease run the program again ");
        puts(BLUE"Thank you for using \"TEMPLE HUMAN RESOURCES\" "RESET);
        exit(1);
    }
    printf("Enter Hourly Salary: ");
    scanf("%lf",&Hourly_rate);
    if(check_input(Hourly_rate)==0){
        puts("\tThis is not a valid hourly salary amount. \n\tPlease run the program again ");
        puts(BLUE"Thank you for using \"TEMPLE HUMAN RESOURCES\" "RESET);
        exit(1);
    }
    printf("Enter Weekly Time: ");
    scanf("%lf",&Weekly_time);
    if(check_input(Weekly_time)==0){
        puts("\tThis is not a weekly time. \n\tPlease run the program again ");
        puts(BLUE"Thank you for using \"TEMPLE HUMAN RESOURCES\" "RESET);
        exit(1);
    }
    double  Net_pay= net_pay(Hourly_rate,Weekly_time,&Regular_pay,&Overtime_pay);
    toString(Employee_id,Hourly_rate,Weekly_time,Net_pay,Regular_pay,Overtime_pay);
    puts(BLUE"Thank you for using \"TEMPLE HUMAN RESOURCES\" "RESET);
    return 0;
}
/*
 * @function check_input:This function checks if the input "x" is a positive non-negative
 * decimal number and returns 0 if it is and 1 otherwise.
 * @param double x
 * */

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
double net_pay(double Hourly_rate, double Weekly_time,double *Regular_pay,double *Overtime_pay){
    double over_time,net_pay;
    if(Weekly_time>40){
        over_time = Weekly_time-40;
        Weekly_time = 40;
        net_pay = Weekly_time*Hourly_rate + over_time*(1.5*Hourly_rate);
        *Regular_pay = Weekly_time*Hourly_rate;
        *Overtime_pay = over_time*(1.5*Hourly_rate);
    }
    else{
        net_pay = Weekly_time*Hourly_rate;
        *Regular_pay = net_pay;
    }
    return net_pay;
}

void toString(double Employee_id, double Hourly_rate, double Weekly_time,
              double Net_pay, double Regular_pay,double Overtime_pay){
    puts("================================");
    printf("\tEmployee #: %d\n",(int)Employee_id);
    printf("\tHourly Salary: $%.2f\n",Hourly_rate);
    printf("\tWeekly Time: %.2f\n",Weekly_time);
    printf("\tRegular Pay: $%.2f\n",Regular_pay);
    printf("\tOvertime Pay: $%.2f\n",Overtime_pay);
    printf("\tNet Pay: $%.2f\n", Net_pay);
    puts("================================");

}