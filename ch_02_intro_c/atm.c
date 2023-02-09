//
// Created by Fuad Hassan on 2/6/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define RED "\e[0;31m"
#define BLUE "\e[0;34m"
#define RESET "\x1b[0m"
#define PIN 3014
void balance_(double balance);
double deposit_(double balance,double *total_deposit);
double withdraw_(double balance,double *total_withdraw);
int withdraw_validation(double amount);
void receipt();
int quit(char *name,int total_num_of_transactions);


int get_access();
int main(){
    int action;
    int total_num_of_transactions=0;
    char *name = "Nana";
    double balance = 5000,*total_deposit, *total_withdraw;
    double withdraw;
    puts(BLUE"Welcome to \"TEMPLE ATM Machine\" "RESET);
    if(get_access()==1){
        printf("%s your initial balance %.2f\n",name,balance);
        do {
            puts("Menu options");
            puts("\t1. Balance");
            puts("\t2. Deposit");
            puts("\t3. Withdraw");
            puts("\t4. Quit");
            puts("Use the keypad to pick an option");
            scanf("%d",&action);
            switch (action) {
                case 1:
                    balance_(balance);
                    break;
                case 2:
                    balance = deposit_(balance,&total_deposit);
                    receipt();
                    total_num_of_transactions++;
                    break;
                case 3:
                    balance = withdraw_(balance,&total_withdraw);
                    receipt();
                    total_num_of_transactions++;
                    break;
                case 4:
                    quit(name,total_num_of_transactions);
                default:
                    puts(RED"INVALID INPUT"RESET);
            }
        } while (action!=4);
    }

    return 0;
}
void balance_(double balance){
    printf("Your current balance is %.2f\n",balance);
}
double deposit_(double balance,double *total_deposit){
    int attempts;
    double deposit;
    printf("Enter the amount you want to deposit: ");
    scanf("%lf",&deposit);

    *total_deposit += deposit;
    return balance+deposit;
}


double withdraw_(double balance,double *total_withdraw){
    int attempt;
    double withdraw;
    do {
        printf("Enter the amount you want to withdraw: ");
        scanf("%lf", &withdraw);
        if(withdraw_validation(withdraw)==1 && *total_withdraw>=1000){
            puts(RED"YOU REACHED THE MAX LIMIT FOR THE DAY"RESET);
            return balance;
        }
        else if(withdraw_validation(withdraw)==1) {
            *total_withdraw += withdraw;
            return balance - withdraw;
        } else {
            puts(RED"INVALID INPUT! try again"RESET);
            attempt ++;};
    } while (attempt!=4);
    puts(RED"TOO MANY INVALID INPUT");
    puts("TRANSACTIONS TERMINATED"RESET);
    exit(0);
}
int withdraw_validation(double amount){
    if (amount>0 && amount<=1000 && (int)amount%20==0){
        return 1;
    }
    return 0;
}
void receipt(){
    int ans;
    puts("Would you like a receipt? yes for 1 and no for 2");
    scanf("%d",&ans);
//    if(ans=1){
//        puts("Receipt printing..");
//    }
ans==1?puts("Receipt printing.."):0;
}
int quit(char *name,int total_num_of_transactions){
    printf("Total number of transactions  is %d\n",total_num_of_transactions);
    printf("\tThank You, %s\t",name);
    exit(0);
}

int get_access(){
    int count=0;
    int pin;
    while (PIN!=pin){
        printf("please enter your PIN: ");
        scanf("%d",&pin);
        count++;
        if(count==3 && PIN!=pin){
            puts(RED"INVALID PIN");
            puts("Access denied"RESET);
            exit(0);
        }
    }
    return 1;
}


