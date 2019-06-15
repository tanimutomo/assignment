#include <stdio.h>

int main(void) {
    FILE *fp;
    char fname[] = "test.txt";

    fp = fopen(fname, "r");
    if (fp == NULL) {
        printf("%s file not open!\n", fname);
        return -1;
    } else {
        printf("%s file opened!\n", fname);
    }

    fclose(fp);

    return 0;
}
