//
// Created by Fuad Hassan on 2/6/23.
//
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define RED "\e[0;31m"
#define BLUE "\e[0;34m"
#define RESET "\x1b[0m"
#define PIN 3014
void balance_(double balance);
double deposit_(double balance,double *total_deposit);
double withdraw_(double balance,double *total_withdraw);
int withdraw_validation(double amount);
void receipt();
int check_input(double x);
int quit(char *name,int total_num_of_transactions);
int get_access();


int main(){
    unsigned int action;
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
// Function to display the current balance of the user
// Input: a double value "balance" representing the current balance
// Output: Prints "Your current balance is [balance]" to the console with 2 decimal places.
void balance_(double balance){
    printf("Your current balance is %.2f\n",balance);
}
/*
 * allows a user to deposit an amount to their balance. It takes in two parameters,
 * the first one is "balance", which is the current balance of the user, and the
 * second one is a pointer to a double named "total_deposit", which stores the total
 * amount of deposit made by the user for the day. The function has a loop that runs
 * until the user enters a valid deposit amount or until the maximum limit for the day
 * is reached, or until three invalid inputs are made. The function returns the
 * updated balance after a successful deposit and has built-in error handling for invalid inputs.*/
double deposit_(double balance,double *total_deposit){
    unsigned int attempt=0;
    double deposit;
    do{
        printf("Enter the amount you want to deposit: ");
        scanf("%lf",&deposit);
        if(*total_deposit>=10000){
            puts(RED"YOU REACHED THE MAX LIMIT FOR THE DAY"RESET);
            return balance;
        } else if(check_input(deposit) && deposit<=10000 ){
            *total_deposit += deposit;
            return balance+deposit;
        }else {
            attempt<2 ?puts(RED"INVALID INPUT! try again"RESET):0;
            attempt ++;};
    } while (attempt!=3);
    puts(RED"TOO MANY INVALID INPUT");
    puts("TRANSACTIONS TERMINATED"RESET);
    exit(0);
}
/*
 * allows a user to withdraw an amount from their balance. It takes in two parameters,
 * the first one is "balance", which is the current balance of the user, and the second
 * one is a pointer to a double named "total_withdraw", which stores the total amount of
 * withdrawal made by the user for the day. The function has a loop that runs until
 * the user enters a valid withdrawal amount or until the maximum limit for the day is
 * reached, or until three invalid inputs are made. The function returns the updated
 * balance after a successful withdrawal and has built-in error handling for invalid
 * inputs through the "withdraw_validation()" function.*/
double withdraw_(double balance,double *total_withdraw){
    unsigned int attempt=0;
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
            attempt<2 ?puts(RED"INVALID INPUT! try again"RESET):0;
            attempt ++;};
    } while (attempt!=3);
    puts(RED"TOO MANY INVALID INPUT");
    puts("TRANSACTIONS TERMINATED"RESET);
    exit(0);
}
/*
 * alidates the amount entered by the user for withdrawal. It takes in one parameter,
 * "amount", which is the amount entered by the user for withdrawal. The function
 * checks if the amount is greater than 0, less than or equal to 1000 and a multiple
 * of 20. If all conditions are met, it returns 1, indicating that the amount is valid for withdrawal.*/
int withdraw_validation(double amount){
    if (amount>0 && amount<=1000 && (int)amount%20==0){
        return 1;
    }
    return 0;
}
/*
 * This function is for printing a receipt after a transaction. The user is prompted
 * to choose between "yes" or "no" for a receipt by entering 1 or 2. If 1 is entered,
 * a message "Receipt printing.." is displayed.*/
void receipt(){
    unsigned short ans;
    puts("Would you like a receipt? yes for 1 and no for 2");
    scanf("%hd",&ans);
    ans==1?puts("Receipt printing.."):0;
}
/*
 * This function terminates the program and displays the total number of transactions
 * made by the user, along with a message thanking them by name.*/
int quit(char *name,int total_num_of_transactions){
    printf("Total number of transactions  is %d\n",total_num_of_transactions);
    printf("\tThank You, %s\n",name);
    exit(0);
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
/*
 * function verifies a user's PIN and grants access if it is correct. After three
 * incorrect attempts, it terminates the program.*/

int get_access(){
    int count=0;
    double pin;

    while (check_input(pin)==0 || PIN!=(int)pin){
        printf("please enter your PIN: ");
        scanf("%lf",&pin);

        count++;
        if(count==3 && PIN!=pin){
            puts(RED"INVALID PIN");
            puts("Access denied"RESET);
            exit(0);
        }
    }
    return 1;
}


