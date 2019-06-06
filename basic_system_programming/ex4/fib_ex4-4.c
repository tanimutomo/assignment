#include <stdio.h>
#include <stdlib.h>

int fib(unsigned long int n) {
    if (n == 1 || n == 2) {
        return 1;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}

int main() {
    unsigned long int i;
    for (i = 1; i <= 40; i++) {
        printf("Fibonacci %u is %u\n", i, fib(i));
    }
    exit(0);
}
