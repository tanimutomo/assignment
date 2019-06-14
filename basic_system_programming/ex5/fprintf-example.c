#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    fp = fopen("output", "w");
    fprintf(fp, "Hello C World\n");
    fclose(fp);
    exit(0);
}
