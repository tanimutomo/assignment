#include <stdio.h>
#include <stdlib.h>

int i;
int main(int argc, char *argv[]) {
    if (argc > 1) {
        for (i=1; i<argc; i++) {
            printf("%s ", argv[i]);
        }
        printf("\n");
    }
    exit(0);
}
