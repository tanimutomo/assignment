#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 101


int main() {
    int factors[MAX_NUM];

    // Get the factors for each number
    for (int num = 2; num < MAX_NUM; num++) {
        // Initialize the factors
        for (int i = 0; i < MAX_NUM; i++) {
            factors[i] = 0;
        }

        // Calculate the factors
        int i = 2;
        int j = 0;
        int tmp = num;
        while (1) {
            if (tmp % i == 0) {
                factors[j] = i;
                j++;
                tmp = tmp / i;
                if (tmp == 1) {
                    break;
                }
            } else {
                i++;
            }
        }

        // print the factors
        printf("%d = ", num);
        i = 0;
        while (1) {
            printf("%d", factors[i]);
            if (factors[i+1] == 0) {
                printf("\n");
                break;
            } else {
                printf(" x ");
            }
            i++;
        }
    }
    exit(0);
}
