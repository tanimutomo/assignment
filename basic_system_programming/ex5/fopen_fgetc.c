#include <stdio.h>

int main() {
    FILE *fp;
    int c;
    fp = fopen("test.txt", "r");
    if (fp == NULL) {
        printf("File open error\n");
        return 0;
    } else {
        printf("File is opend!\n");
    }

    for (;;) {
        c = fgetc(fp);
        if (c == -1) {
            break;
        }
        printf("%c\n", c);
    }
    fclose(fp);
}
