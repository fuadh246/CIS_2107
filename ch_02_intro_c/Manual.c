/*
 * Name:	Faud Hassan
 * Section:	01
 * Lab:  	CIS2107_Lab08_Manual 
 * Goal: 	To design and implement functions taking pointers as arguments 
			to process characters and strings.
 */


#include <stdio.h>
#include <memory.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//functions prototypes
void * upperLower(const char * s);
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4);
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4);
void compareStr(const char *s1, const char *s2);
void comparePartialStr(const char *s1, const char *s2, int n);
void randomize(void);
int tokenizeTelNum(char *num);
void reverse(char *text);
int countSubstr (char * line, char * sub);
int countChar (char * line, char c);
int countWords(char *string);
void countAlpha(char *string);
void startsWithB(char *string[],int size);
void endsWithed(char *string[], int size);

int main() {

    //random generator
    srand(time(NULL));

    //test for upperLower
    const char test[] = "This iS A Test";
    upperLower(test);

    //test for convertStrtoInt
    printf("\n\nThe sum of 4 strings is: %d", convertStrtoInt("3", "4", "5", "6"));

    //test for convertStrtoFloat
    printf("\n\nThe sum of 4 strings is: %.2f", convertStrtoFloat("3.5", "4.5", "5.5", "6.5"));

    //test for compareStr
    puts("");
    compareStr("Test1", "Test2");

    //test for comparePartialStr
    comparePartialStr("Test1", "Test2", 4);

    //test for randomize
    randomize();

    //test for tokenize number
    char str[] = "(267) 436-6281";
    tokenizeTelNum(str);

    //test for reverse
    char line[] = "Hello world";
    reverse(line);

    //test for countSubstr
    char *line1 = "helloworldworld";
    char *substring = "world";
    printf("\n\nNumber of Substrings %s inside %s: %d\n", substring, line1, countSubstr(line1, substring));

    //test for countChar
    char w = 'w';
    printf("\nNumber of character %c inside %s: %d\n", w, line1, countChar(line1, w));

    //test for countAlpha
    char str1[] = "Hello it's me.";
    countAlpha(str1);

    //test for countWords
    char countstring[] = "hello world!";
    printf("\n\nNumber of words in string is: %d\n", countWords(countstring));

    //test for startsWithB
    char *series[] = {"bored", "hello", "Brother", "manual", "bothered"};
    int size = sizeof(series) / sizeof(series[0]);
    startsWithB(series,size);

    //test for endsWithed
    puts("");
    endsWithed(series,size);

}

// 1.(Displaying Strings in Uppercase and Lowercase)
void * upperLower (const char * s) {
    const char *sPtr = s;
    while (*s!=0){
        printf("%c", toupper(*s));
        s++;
    }
    puts("");
// we had to initiate the *sPtr to go back to the location 0;
    while (*sPtr!=0){
        printf("%c", tolower(*sPtr));
        sPtr++;
    }

}

// 2.(Converting Strings to Integers for Calculations)
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4) {
    return atoi(s1)+ atoi(s2)+ atoi(s3)+ atoi(s4);
}

//3.(Converting Strings to Floating Point for Calculations)
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4) {
    return atof(s1)+ atof(s2)+ atof(s3)+ atof(s4);
}

//4.(Comparing Strings)
void compareStr(const char *s1, const char *s2) {
    int difference = strcmp(s1,s2);
    if (difference<s1){
        puts("s1 < s2");
    } else if(difference>s1){
        puts("s1 > s2");
    } else{
        puts("s1 == s2");
    }
}

//5.(Comparing Portions of Strings)
void comparePartialStr(const char *s1, const char *s2, int n) {
    for (int i = 0; i < n; ++i) {
        if (*s1!=*s1){
            break;
        }
        s1++,s2++;
    }
    if (*s2<*s1){
        puts("s1 < s2");
    } else if(*s2>*s1){
        puts("s1 > s2");
    } else{
        puts("s1 == s2");
    }
}

//6.(Random Sentences)
void randomize(void) {

    char* articles[] = {"the", "a", "one", "some", "any"};
    char* nouns[] = {"boy", "girl", "dog", "town", "car"};
    char* verbs[] = {"drove", "jumped", "ran", "walked", "skipped"};
    char* prepositions[] = {"to", "from", "over", "under", "on"};
    for (int i = 0; i < 20; ++i) {
        char sentence[120]="";

        strcat(sentence, articles[rand() % 5]);
        strcat(sentence, " ");
        strcat(sentence, nouns[rand() % 5]);
        strcat(sentence, " ");
        strcat(sentence, verbs[rand() % 5]);
        strcat(sentence, " ");
        strcat(sentence, prepositions[rand() % 5]);
        strcat(sentence, " ");
        strcat(sentence, articles[rand() % 5]);
        strcat(sentence, " ");
        strcat(sentence, nouns[rand() % 5]);
        strcat(sentence, ". ");
        sentence[0]= toupper(sentence[0]);
        printf("%s\n", sentence);
    }
}
//7.(Tokenizing Telephone Numbers)
int tokenizeTelNum(char *telNum) {
    char *token;
    char areaCode[3], firstThree[3], lastFour[4], phoneNumber[9];
    token = strtok(telNum, "()");
    strcpy(areaCode, token);
    token = strtok(NULL, "-");
    strcpy(firstThree, token);
    token = strtok(NULL, "-");
    strcpy(lastFour, token);
    strcat(phoneNumber,firstThree);
    strcat(phoneNumber,lastFour);
    int areaCodeInt = atoi(areaCode);
    long phoneNumberLong = atol(phoneNumber);
    printf("Phone number: %d %ld\n",areaCodeInt, phoneNumberLong);
}



//8.(Displaying a Sentence with Its Words Reversed)
void reverse(char *text) {
    char *token;
    char *tokens[strlen(text)];
    int token_numbers = 0;

    // Tokenize the string and store the tokens in an array
    token = strtok(text, " ");
    while (token != NULL) {
        tokens[token_numbers++] = token;
        token = strtok(NULL, " ");
    }

    // Output the tokens in reverse order
    for (int i = token_numbers - 1; i >= 0; i--) {
        printf("%s ", tokens[i]);
    }
    printf("\n");
}

//9.(Counting the Occurrences of a Substring)
int countSubstr (char * line, char * sub) {
    int count = 0;
    char *lnPtr=line;
    while ((*lnPtr) != '\0'){
        if(strncmp(lnPtr, sub, strlen(sub)) == 0){
            count++;
        }
        lnPtr++;
    }
    return count;
}

//10.(Counting the Occurrences of a Character)
int countChar (char *line, char c) {
    int count = 0;

    while(*line != '\0'){
        if(*line == c){
            count++;
        }
        line++;
    }
    return count;
}


//11.(Counting the Letters of the Alphabet in a String)
void countAlpha(char *string) {
    int Alphabets[26]={0};
    char c;
    while (*string!='\0'){
        c= tolower(*string);
        if(c >= 'a' && c <= 'z'){
            Alphabets[c - 'a'] += 1;
        }
        string++;
    }
    printf("\n%-9s| %-15s", "Letter", "Occurrences");
    for(short i = 0; i < 26; i++){
        if(Alphabets[i] > 0)
            printf("\n%c,%-10c %-15d", 'A'+i,'a'+i, Alphabets[i]);
    }
}

//12.(Counting the Number of Words in a String)
int countWords(char *string) {
    int count=0;
    char *token;
    token= strtok(string," ");
    while (token!=NULL){
        count++;
        token= strtok(NULL," ");
    }
    return count;
}

//13.(Strings Starting with "b")
void startsWithB(char *string[],int size){
    for (int i = 0; i < size; ++i) {
        if (tolower(*(string[i]+0))=='b'){
            printf("%s\n", string[i]);
        }
    }
}

//14.(Strings Ending with "ed")
void endsWithed(char *string[], int size){
    for (int i = 0; i < size; ++i) {
        int string_len = strlen(string[i]);
        if(string_len<2) continue;
        if (strcmp(string[i]+(string_len-2),"ed")==0){
            printf("%s\n", string[i]);
        }
    }
}