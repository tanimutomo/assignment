#include <stdio.h>
#include <stdlib.h>

int main(){
    int x, y; int *p;

    p = &x;
    x = 7;
    y = *p;
    *p = 3;
    printf("x = %d, y = %d\n", x, y);
    printf("*p = %d\n", *p);
    printf("x = %d, &x = %p\n", x, &x);
    printf("p = %p, &p = %p\n", p, &p);
    printf("&x = %p, &y = %p\n", &x, &y);
    exit(0);
}
