void take_last(char *s, int n) {
    int len = 0;
    char *sPtr = s;
    while (*sPtr != '\0') {
        len++;
        sPtr++;
    }
    if (n < len) {
        int start_from = len - n;
        char *temp=s + start_from;
        while (*temp!='\0'){
            *s=*temp;
            s++,temp++;
        }
        *s = '\0';
    }
}
