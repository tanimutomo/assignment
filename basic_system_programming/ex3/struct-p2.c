#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 256

struct bunsuu {
    int shi, bo;
};

void keisan(struct bunsuu *p,
            struct bunsuu *q,
            struct bunsuu *r) {
    (*r).shi = (*p).shi * (*q).bo + (*p).bo * (*q).shi;
    (*r).bo = (*p).bo * (*q).bo;
    return ;
}

int main() {
    int ret;
    char input[MAXLINE];
    struct bunsuu a, b, c;

    fgets(input, MAXLINE, stdin);
    ret = sscanf(input, "%d/%d", &a.shi, &a.bo);
    if (ret != 2) {exit(1);}
    fgets(input, MAXLINE, stdin);
    ret = sscanf(input, "%d/%d", &b.shi, &b.bo);
    if (ret != 2) {exit(1);}

    keisan(&a, &b, &c);
    printf("%d/%d + %d/%d = %d/%d\n",
            a.shi, a.bo, b.shi, b.bo, c.shi, c.bo);
    exit(0);
}

