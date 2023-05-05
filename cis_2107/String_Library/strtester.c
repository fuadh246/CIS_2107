
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#define RED "\e[0;31m"
#define BLUE "\e[0;34m"
#define RESET "\x1b[0m"
int main()
{
    puts(BLUE"Test for all_letters"RESET);
    char *s = "hello";
    char *s1 = "sir";
    int all_letters_ = all_letters(s);
    if (all_letters_)
    {
        printf("String: %s\n", s);
        puts("All characters are in string are letters");
    }
    else
    {
        puts("All characters are " BLUE "NOT " RESET "in string are letters");
    }
    puts("");
    puts(BLUE"Test for all_letters"RESET);
    int num_in_range_ = num_in_range(s,'h','l');
    printf("String: %s\n",s);
    printf("There are %d letter in the string\n",num_in_range_);

    puts("");
    puts(BLUE"Test for diff tester"RESET);
    int diff_= diff("book","back");
    printf("book and back are different %d way(s)\n",diff_);
    puts("Test for diff shorten");
    char word[] = "Hello";
    shorten(word, 3);
    printf("The shorten word is %s\n",word);

    puts("");
    puts(BLUE"test for len_diff"RESET);
    int len_diff_ = len_diff("Philadelphia","Hello");
    printf("The len different is %d\n",len_diff_);

    puts("");
    puts(BLUE"test for rm_left_space"RESET);
    char rm_left_space_[] = "    Hello";
    printf("Before: %s\n",rm_left_space_);
    rm_left_space(rm_left_space_);
    printf("After: %s\n",rm_left_space_);

    puts("");
    puts(BLUE"test for rm_right_space"RESET);
    char rm_right_space_[]="hello   ";
    printf("Before: %s\n",rm_right_space_);
    rm_right_space(rm_right_space_);
    printf("After: %s\n",rm_right_space_);

    puts("");
    puts(BLUE"test for rm_space"RESET);
    char rm_space_[]="   hello   ";
    printf("Before: %s\n",rm_space_);
    rm_space(rm_space_);
    printf("After: %s\n",rm_space_);

    puts("");
    puts(BLUE"test for find"RESET);    
    find("hello","l") ? printf("l was found at index %d\n",find("hello","l")) : printf("Not found\n");

    puts("");
    puts(BLUE"test for ptr_to"RESET);
    char hello[] = "Hello";
    char n[] = "l";
    char *result = ptr_to(hello,  n);
    if (result != NULL) {
        printf("Found '%s' at address %p\n", n, (void *) result);
    } else {
        printf("'%s' not found in '%s'\n", n, hello);
    }

    puts("");
    puts(BLUE"test for  is_empty"RESET);
    char is_empty_[] = "     ";
    is_empty(is_empty_) ? printf("\'%s\' is  empty\n",is_empty_): printf("\'%s\' is NOT empty\n",is_empty_);

    puts("");

    puts(BLUE"test for str_zip"RESET);
    char str_zip_1[]="Temple";
    char str_zip_2[]="Hello";
    char *str_zip_r= str_zip(str_zip_1,str_zip_2);
    printf("\'%s\' and \'%s\" str_zip is \'%s\'\n",str_zip_1,str_zip_2,str_zip_r);

    puts("");

    puts(BLUE"test for capitalize"RESET);
    char capitalize_[]= "hello word";
    printf("Before: %s\n",capitalize_);
    capitalize(capitalize_);
    printf("After: %s\n",capitalize_);
    
    puts("");

    puts(BLUE"test for strcmp_ign_case"RESET);
    char strcmp_ign_case_1[]="hello";
    char strcmp_ign_case_2[]="hello";
    strcmp_ign_case(strcmp_ign_case_1, strcmp_ign_case_2) ? printf("\'%s\' and \'%s\' are not the same\n", strcmp_ign_case_1, strcmp_ign_case_2) : printf("\'%s\' and \'%s\' are the same\n", strcmp_ign_case_1, strcmp_ign_case_2);

    puts("");

    puts(BLUE"test for take_last"RESET);
    char take_last_[]="hello";
    printf("Before: %s\n",take_last_);
    take_last(take_last_,3);
    printf("After: %s\n",take_last_);

    puts("");

    puts(BLUE"test for dedup"RESET);
    char dedup_[]="hello";
    printf("Before: %s\n",dedup_);
    char *dedup_r = dedup(dedup_);
    printf("After: %s\n",dedup_r);

    puts("");

    puts(BLUE"test for pad"RESET);
    char pad_[]="hello";
    printf("Before: %s\n",pad_);
    char *pad_r = pad(pad_,6);
    printf("After: \'%s\'\n",pad_r);

    puts("");

    puts(BLUE"test for ends_with_ignore_case"RESET);
    char ends_with_ignore_case_1[]="hello";
    char ends_with_ignore_case_2[]="lo";
    ends_with_ignore_case(ends_with_ignore_case_1, ends_with_ignore_case_2) ? printf("\'%s\' ends with \'%s\'\n", ends_with_ignore_case_1, ends_with_ignore_case_2) : printf("\'%s\' ends with \'%s\'\n", ends_with_ignore_case_1, ends_with_ignore_case_2);

    puts("");

    puts(BLUE"test for repeat"RESET);
    char repeat_[]="hello";
    printf("Before: %s\n",repeat_);
    char *repeat_r = repeat(repeat_,6,'-');
    printf("After: \'%s\'\n",repeat_r);

    puts("");

    puts(BLUE"test for replace"RESET);
    char replace_[]="Steph is the X";
    printf("Before: %s\n",replace_);
    char *replace_r = replace(replace_,"X","best");
    printf("After: \'%s\'\n",replace_r);

    puts("");

    puts(BLUE"test for str_connect"RESET);
    char *str_connect_arr[] = {"Hello", "world", "Hello", "world"};
    printf("Before: %s\n", *str_connect_arr);
    char *str_connect_r = str_connect(str_connect_arr, 4, '-');
    printf("After: \'%s\'\n", str_connect_r);

    puts("");

    puts(BLUE"test for rm_empties"RESET);
    char* words[] = {"hello", "", "world", "", "!", NULL};
    printf("Before: ");
    for (int i = 0; words[i] != NULL; i++) {
        printf("\'%s\'", words[i]);
    }
    printf("\n");

    rm_empties(words);

    printf("After: ");
    for (int i = 0; words[i] != NULL; i++) {
        printf("\'%s\'", words[i]);
    }
    printf("\n");

    puts("");

    puts(BLUE"test for str_chop_all"RESET);
    char str_chop_all_[] = "Hello/world/hello/world";
    char **str_chop_all_r = str_chop_all(str_chop_all_, '/');
    int i = 0;
    while (str_chop_all_r[i] != NULL) {
        printf("%s, ", str_chop_all_r[i]);
        free(str_chop_all_r[i]);
         i++;
    }
    free(str_chop_all_r);
    printf("\n"BLUE"\nDONE\n\n\n\n"RESET);
    return 0;
}
