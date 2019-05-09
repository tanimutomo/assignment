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

int lcm(int a, int b){
    int c, start, base;
    if (a == b){
        return a;
    } else if (a < b){
        start = b - (b % a);
        base = a;
    } else {
        start = a - (a % b);
        base = b;
    }
    for (int i = 0; i <= 10000; i++){
        c = start + i*base;
        if (c % a == 0 && c % b == 0){
            return c;
        }
    }
    return 0;
}

int main(){
    int input1, input2, res_gcd, res_lcm;
    input1 = 1001;
    input2 = 33;
    res_gcd = gcd(input1, input2);
    res_lcm = lcm(input1, input2);
    printf("G.C.D.: %d, L.C.M.: %d\n", res_gcd, res_lcm);
    return 0;
}


