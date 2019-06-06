#include <stdio.h>
#include <stdlib.h>

int factorial(unsigned long int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    unsigned long int i;
    for (i = 1; i <= 20; i++) {
        printf("Factorial %u is %u\n", i, factorial(i));
    }
    exit(0);
}
