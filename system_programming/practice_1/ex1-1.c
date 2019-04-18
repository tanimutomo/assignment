#include <stdio.h>

int main(){
    int pre1, pre2, now;
    pre1 = 1;
    pre2 = 1;
    now = 0;
    printf("%d\n", pre1);
    printf("%d\n", pre2);
    for (int i = 0; i < 31; i++) {
        now = pre2 + pre1;
        // printf("pre1: %d, pre2: %d, now: %d\n", pre1, pre2, now);
        printf("%d\n", now);
        pre1 = pre2;
        pre2 = now;
    }
    return 0;
}
