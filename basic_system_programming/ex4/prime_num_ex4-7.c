#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 10001

int main() {
    char prime[MAX_NUM];
    int i, j;

    // Initializaiton
    for (i = 0; i < MAX_NUM; i++) {
        prime[i] = 1;
    }

    // Apply the Eratosthenes sieve
    for (i = 2; i < MAX_NUM; i++) {
        for (j = 2; j*i < MAX_NUM; j++) {
            prime[j*i] = 0;
        }
    }

    for (i = 1; i < MAX_NUM; i++) {
        if (prime[i] == 1) {
            printf("%d\n", i);
        }
    }
    exit(0);
}
