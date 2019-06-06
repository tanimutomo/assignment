#include <stdio.h>
#include <stdlib.h>

int dbl_factorial(long int n) {
    if (n == 0 || n == -1) {
        return 1;
    } else {
        return n * dbl_factorial(n - 2);
    }
}

int main() {
    long int i;
    for (i = 1; i <= 15; i++) {
        printf("Factorial %d is %d\n", i, dbl_factorial(i));
    }
    exit(0);
}
