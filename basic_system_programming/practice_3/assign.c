#include <stdio.h>
#include <stdlib.h>

int main(){
    int s;
    s = 0;

    double d = 0.1;
    char c[9] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
    int i[4] = {1, 2, 3, 4};

    int e;
    e = 0;

    printf("s = %d, &s = %p\n", s, &s);
    printf("d = %f, &d = %p\n", d, &d);
    printf("&c = %p\n", &c);
    printf("c[0] = %d, &c[0] = %p\n", c[0], &c[0]);
    printf("c[1] = %d, &c[1] = %p\n", c[1], &c[1]);
    printf("c[8] = %d, &c[8] = %p\n", c[8], &c[8]);
    printf("&i = %p\n", &i);
    printf("i[0] = %d, &i[0] = %p\n", i[0], &i[0]);
    printf("i[1] = %d, &i[1] = %p\n", i[1], &i[1]);
    printf("i[3] = %d, &i[3] = %p\n", i[3], &i[3]);
    printf("e = %d, &e = %p\n", e, &e);

    exit(0);
}
