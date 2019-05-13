#include <stdio.h>
#include <stdlib.h>


int shisoku(int *x, int *y, int *wa, int *sa, int *seki, int *shou) {
    // execute arithmetric operations and store the results
    *wa = *x + *y;
    *sa = *x - *y;
    *seki = *x * *y;
    
    // In the case of y is 0, return 0.
    if (*y == 0) {
        return 0;
    // In the case of y is not 0, execute division operation and return 1.
    } else {
        *shou = *x / *y;
        return 1;
    }
}

int main() {
    // define the input constant
    int x = 10, y = 0;
    // define the variables for storing calcurated results
    int wa, sa, seki, shou;

    // In the case that returned value is 1, print all operation results.
    if (shisoku(&x, &y, &wa, &sa, &seki, &shou) == 1) {
        printf("x + y = %d, x - y = %d, x * y = %d, x / y = %d\n", wa, sa, seki, shou);
    // In the case that returned value is 0, print three operation results except for division.
    } else {
        printf("x + y = %d, x - y = %d, x * y = %d, x / y = XXX\n", wa, sa, seki);
    }
    exit(0);
}
