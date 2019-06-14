#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 512


int main() {
    FILE *fp;
    char input[MAXLEN];
    fp = fopen("output", "r");
    if (fp == NULL) {
        fprintf(stderr, "fopen error\n");
        exit(1);
    }
    fgets(input, MAXLEN, fp);
    fclose(fp);
    printf("%s", input);
    exit(0);
}
