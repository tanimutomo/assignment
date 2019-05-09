#include <stdio.h>
#include <stdlib.h>

void sort(int *a, int *b, int *c) {
    int tmp;
    if (*b < *c) {
        tmp = *b;
        *b = *c;
        *c = tmp;
    }
    
    if (*a < *c) {
        tmp = *a;
        *a = *c;
        *c = tmp;
    }

    if (*a < *b) {
        tmp = *a;
        *a = *b;
        *b = tmp;
    }

    return;
}

int main() {
    int p, q, r;
    p = 1; q = 2, r = 3;
    sort(&p, &q, &r);
    printf("In main: p=%d, q=%d, r=%d\n", p, q, r);
    exit(0);
}

