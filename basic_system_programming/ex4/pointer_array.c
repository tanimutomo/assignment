#include <stdio.h>


int main() {
    int array[5];
    int n = 5;

    int *p;

    p = &array[0];

    for (int i = 0; i < n; i++) {
        p[i] = 2*i;
    }
    
    for (int i = 0; i < n; i++) {
        printf("%d\n", array[i]);
    }

    int i = 1, j;
    j = i;
    i = 2;
    printf("i = %d\n", i);
    printf("j = %d\n", j);

    
}
