#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 256


int main() {
    FILE *fp;
    char line[MAXLINE];
    line[0] = '\0';
    fp = fopen("text.txt", "r");
    if (fp == NULL) {
        printf("File cannot be opened\n");
        exit(1);
    }

    while (fgets(line, MAXLINE, fp) != NULL) {
        printf("%s", line);
    }
    fclose(fp);
}

