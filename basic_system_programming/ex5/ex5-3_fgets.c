#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 256


int main(int argc, char *argv[]) {
    // Exception Handling
    if (argc != 2) {
        printf("Please specify a file name\n");
    }

    FILE *fp;
    char line[MAXLINE];
    line[0] = '\0';
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("File cannot be opened\n");
        exit(1);
    }

    while (fgets(line, MAXLINE, fp) != NULL) {
        printf("%s", line);
    }
    fclose(fp);

    return 0;
}

