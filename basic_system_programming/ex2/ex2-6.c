#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 256

struct frac {
    int shi, bo;
};

int gcd(int a, int b) {
    int c;
    while(b != 0){
        c = a % b;
        a = b;
        b = c;
        //printf("a:%d, b:%d, c:%d\n", a, b, c);
    }
    return a;
}

int main() {
    int ret, gcd_;
    char input[MAXLINE];
    struct frac f, g, h;

    fgets(input, MAXLINE, stdin);
    ret = sscanf(input, "%d/%d", &f.shi, &f.bo);
    if (ret != 2) {exit(1);}
    fgets(input, MAXLINE, stdin);
    ret = sscanf(input, "%d/%d", &g.shi, &g.bo);
    if (ret != 2) {exit(1);}

    h.shi = f.shi * g.bo + g.shi * f.bo;
    h.bo = f.bo * g.bo;

    gcd_ = gcd(h.shi, h.bo);
    if (gcd_ != 1) {
        h.shi /= gcd_;
        h.bo /= gcd_;
    }

    printf("%d/%d + %d/%d = %d/%d\n",
            f.shi, f.bo, g.shi, g.bo, h.shi, h.bo);
    exit(0);
}


