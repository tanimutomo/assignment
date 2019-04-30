#include <stdio.h>
#include <stdlib.h>

int main(){
    int x; int *p;
    x = 7;
    p = &x;
    printf("x = %d, &x = %p\n", x, &x);
    printf("p = %p, *p = %d\n", p, *p);
    printf("&p = %p\n", &p);
    exit(0);
}

