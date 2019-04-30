#include <stdio.h>
#include <stdlib.h>

int main(){
    unsigned int i;
    char a;
    unsigned int j;

    i = 10; j = 15; a = 'A';
    printf("i = %d, &i = %p\n", i, &i);
    printf("j = %d, &j = %p\n", j, &j);
    printf("a = %d, &a = %p\n", a, &a);
    exit(0);
}
