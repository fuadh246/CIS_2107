//
// Created by Fuad Hassan on 3/9/23.
//
// txt file with all the words
// we will randomly pick one word
// track time
// user type
// check if its right
// 3
// finish time

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>

#define MAX_WORD_LEN 20
#define MAX_NUM_WORDS 10
#define MAX_TIME 60

void clear_screen();
void print_word(char *word);
void shuffle_words(char words[MAX_NUM_WORDS][MAX_WORD_LEN], int num_words);
void get_user_input(char *input);
int check_input(char *word, char *input);

int main() {
    char words[MAX_NUM_WORDS][MAX_WORD_LEN] = {"apple", "banana", "orange", "peach", "grape", "kiwi", "mango", "pear", "pineapple", "watermelon"};
    int num_words = sizeof(words) / sizeof(words[0]);
    int score = 0;
    int time_left = MAX_TIME;
    char input[MAX_WORD_LEN];
    time_t start_time, end_time;

    srand(time(NULL));  // initialize random seed
    shuffle_words(words, num_words);  // shuffle the order of words

    clear_screen();
    printf("Welcome to the typing game!\n");
    printf("You have %d seconds to type as many words as possible.\n", MAX_TIME);
    printf("Press ENTER to start.\n");
    getchar();  // wait for user to press ENTER

    time(&start_time);
    while (time_left > 0) {
        clear_screen();
        printf("Time left: %d seconds\n", time_left);
        printf("Score: %d\n", score);
        print_word(words[score % num_words]);  // print the current word
        get_user_input(input);  // wait for user input
        if (check_input(words[score % num_words], input)) {  // check if input matches the word
            score++;
        }
        time(&end_time);
        time_left = MAX_TIME - difftime(end_time, start_time);
    }

    clear_screen();
    printf("Time's up! Your final score is %d.\n", score);

    return 0;
}

void clear_screen() {
    printf("\033[2J\033[1;1H");  // ANSI escape code to clear screen
}

void print_word(char *word) {
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t%s\n", word);
}

void shuffle_words(char words[MAX_NUM_WORDS][MAX_WORD_LEN], int num_words) {
    for (int i = num_words - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp[MAX_WORD_LEN];
        strcpy(temp, words[i]);
        strcpy(words[i], words[j]);
        strcpy(words[j], temp);
    }
}

void get_user_input(char *input) {
    printf("\t\t\t\t\t");
    fgets(input, MAX_WORD_LEN, stdin);
    input[strcspn(input, "\n")] = '\0';  // remove newline character from input
}

int check_input(char *word, char *input) {
    if (strcmp(word, input) == 0) {
        return 1;
    } else {
        return 0;
    }
}
