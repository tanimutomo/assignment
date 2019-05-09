#include <stdio.h>
#include <stdlib.h>

int main(){
    unsigned int p;
    unsigned long long a;

    p = 439467295U;
    printf("p=%d\n", p);
    printf("p=%u\n", p);
    a = 1233455667788987456ULL;
    printf("a=%d\n", a);
    printf("a=%u\n", a);
    printf("a=%lld\n", a);
    printf("a=%llu\n", a);
    exit(0);
}
