#include <stdio.h>
#include <stdlib.h>

void two_order(int *a, int *b) {
    int c;
    if (*a < *b) {
        c = *a;
        *a = *b;
        *b = c;
    }
    return;
}

int main() {
    int p, q;
    p = 10; q = 12;
    two_order(&p, &q);
    printf("In main: p=%d, q=%d\n", p, q);
    exit(0);
}

