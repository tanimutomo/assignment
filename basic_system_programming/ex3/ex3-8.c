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
    }
    return a;
}

void frac_operations(char operation,
                     struct frac *p,
                     struct frac *q,
                     struct frac *r) {
    int gcd_;
    // execute operations
    if (operation == '+') {
        // add
        r->shi = p->shi * q->bo + p->bo * q->shi;
        r->bo = p->bo * q->bo;
    } else if (operation == '-') {
        // sub
        r->shi = p->shi * q->bo - p->bo * q->shi;
        r->bo = p->bo * q->bo;
    } else if (operation == '*') {
        // mul
        r->shi = p->shi* q->shi;
        r->bo = p->bo * q->bo;
    } else {
        // div
        r->shi = p->shi * q->bo;
        r->bo = p->bo * q->shi;
    }
    
    // exception handling
    // The case of containing 0 value
    if (r->shi == 0) {
        printf("%d/%d %c %d/%d = 0\n",
                p->shi, p->bo, operation, q->shi, q->bo);
        return;
    } else if (r->bo == 0) {
        if (r->shi > 0) {
            printf("%d/%d %c %d/%d = inf\n",
                    p->shi, p->bo, operation, q->shi, q->bo);
        } else {
            printf("%d/%d %c %d/%d = -inf\n",
                    p->shi, p->bo, operation, q->shi, q->bo);
        };
        return;
    };

    // The case of shi and bo are same value
    if (r->shi == r->bo) {
        if (r->shi * r->bo < 0) {
            printf("%d/%d %c %d/%d = -1\n",
                    p->shi, p->bo, operation, q->shi, q->bo);
        } else {
            printf("%d/%d %c %d/%d = 1\n",
                    p->shi, p->bo, operation, q->shi, q->bo);
        };
        return;
    };

    // Conver to irreducible fraction
    gcd_ = gcd(r->shi, r->bo);
    if (gcd_ != 1) {
        r->shi /= gcd_;
        r->bo /= gcd_;
        printf("%d/%d %c %d/%d = %d/%d\n",
                p->shi, p->bo, operation, q->shi, q->bo, r->shi, r->bo);
        return;
    } else {
        printf("%d/%d %c %d/%d = %d/%d\n",
                p->shi, p->bo, operation, q->shi, q->bo, r->shi, r->bo);
        return;
    };
}

int main() {
    int ret;
    char input[MAXLINE], operations[4] = {'+', '-', '*', '/'};
    struct frac a, b, c;

    // get input values
    fgets(input, MAXLINE, stdin);
    ret = sscanf(input, "%d/%d", &a.shi, &a.bo);
    if (ret != 2) {exit(1);}
    fgets(input, MAXLINE, stdin);
    ret = sscanf(input, "%d/%d", &b.shi, &b.bo);
    if (ret != 2) {exit(1);}

    for (int i=0; i<4; i++){
        frac_operations(operations[i], &a, &b, &c);
    }
    exit(0);
}

