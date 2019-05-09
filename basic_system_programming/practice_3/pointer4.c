#include <stdio.h>
#include <stdlib.h>

int main(){
    unsigned int i;
    char a[8];
    unsigned int j;
    i = 10; j = 15;
    a[0] = 'H'; a[1] = 'E'; a[2] = 'L';
    a[3] = 'L'; a[4] = 'O'; a[5] = '\0';

    printf("i = %d, &i = %p\n", i, &i);
    printf("j = %d, &j = %p\n", j, &j);
    printf("&a = %p\n", &a);
    printf("a[2] = %d, &a[2] = %p\n", a[2], &a[2]);
    printf("a[] = %s\n", a);
    exit(0);
}
