#include <stdio.h>
#include "all_letters.c"
#include "is_empty.c"
#include "capitalize.c"
#include "rm_space.c"
#include "strcmp_ign_case.c"
#include "take_last.c"
#include "dedup.c"
#include "pad.c"
#include "ends_with_ignore_case.c"
#include "repeat.c"
#include "replace.c"
#include "str_connect.c"
#include "rm_empties.c"
#include "str_chop_all.c"
#include "str_zip.c"
int main() {
    char str1[] = "hello woRld";
    char str2[] = "b    ";
    char str3[] = "g";

//    int a = all_letters(str1);
//    rm_space(str1);
//    printf("%s\n", str1);
//    capitalize(str1);
//    printf("%s\n", str1);
//    take_last(str1, 3);
//    printf("%s\n", str1);
//    printf("%s\n", dedup("There's always money in the banana stand."));
//    printf("%s\n", pad("hello", 7));
//    int diff = ends_with_ignore_case("banana", "na");
//    printf("%d\n", diff);
//    printf("%s\n",repeat("Hello",3,'-'));
    replace("MY name name is fuad","name","name");
//    printf("%d\n", strcmp_ign_case(str1,str2));

    printf("%s\n",replace("MY name name is fuad","name","nam"));
    char* strs[] = {"Washington", "Adams", "Jefferson"};
    int n = 3;
    char c = '+';
    char* result = str_connect(strs, n, c);
    printf("%s\n", result);
    free(result);
    char* words[] = {"hello", "", "world", "", "", "foo", "bar", "", NULL};

    printf("Before: [");
    for (int i = 0; words[i] != NULL; i++) {
        printf("%s, ", words[i]);
    }
    printf("NULL]\n");

    rm_empties(words);

    printf("After: [");
    for (int i = 0; words[i] != NULL; i++) {
        printf("%s, ", words[i]);
    }
    printf("NULL]\n");
    char s[] = "I am ready for a nice vacation";

    char** tokens = str_chop_all(s, ' ');
    if (tokens == NULL) {
        printf("Error: memory allocation failed\n");
        return 1;
    }

    printf("{");
    for (int i = 0; tokens[i] != NULL; i++) {
        printf("\"%s\"", tokens[i]);
        if (tokens[i+1] != NULL) {
            printf(", ");
        }
    }
    printf(", NULL}\n");

    // free the memory allocated for the tokens
    for (int i = 0; tokens[i] != NULL; i++) {
        free(tokens[i]);
    }
    free(tokens);

    printf("%s\n",str_zip("Spongebob","Patrick"));

    return 0;
}

