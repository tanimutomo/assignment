#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXLINE 256

int main() {
    char str1[MAXLINE];
    char *s;

    printf("Input the string\n");
    fgets(str1, MAXLINE, stdin);
    s = index(str1, '\n');
    if (s!=NULL) {
        *s = '\0';
    }
    printf("The input is %s\n", str1);
    for (s = str1; *s != '\0'; s++) {
        if (isdigit(*s)) {
            printf("%c is the number\n", *s);
            continue;
        }
        if (isalpha(*s)) {
            printf("%c is the Alphabet\n", *s);
            if (isxdigit(*s)) {
                printf("this is also used as Hexadecimal\n");
                continue;
            }
        }
        if (isspace(*s)) {
            printf("%c is a space\n", *s);
            continue;
        }
        printf("%c is other character\n", *s);
    }
    exit(0);
}






