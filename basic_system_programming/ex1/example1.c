#include <stdio.h>

int gcd(int a, int b) {
    int c;
    // ユークリッドの互除法を利用した解法
    while(b != 0){
        c = a % b;
        a = b;
        b = c;
        printf("a:%d, b:%d, c:%d\n", a, b, c);
    }
    return a;
}

int main(){
    int i, j, k;
    i = 15;
    j = 6;
    k = gcd(i, j);
    printf("%d\n", k);
    return 0;
}

