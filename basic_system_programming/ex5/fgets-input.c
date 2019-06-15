#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 16

int main() {
    char input[MAXLINE];
    fgets(input, MAXLINE, stdin);
    printf("%s\n", input);
    exit(0);
}
