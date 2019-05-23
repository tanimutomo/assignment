#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXLINE 256


int tsurukame_checker(int tsuru, int kame, int atama, int ashi){
    for (int x = 0; x <= atama; x++){
        if (tsuru*(atama-x) + kame*x == ashi){
            return x;
        }
    }
    return -1;
}


int get_number() {
    char num[MAXLINE];
    char *s;

    while(1) {
        fgets(num, MAXLINE, stdin);
        for (s = num; ; s++) {
            if (*s == '\n') {
                return strtol(num, NULL, 10);
            }
            if (isdigit(*s)) {
                continue;
            } else {
                break;
            }
        }
        printf("Please input a positive integer\n");
    }
}


int main(){
    int tsuru, kame, num_kame;
    tsuru = 2;
    kame = 4;

    while(1) {
        int num_heads, num_legs;

        printf("How many are heads?\n");
        num_heads = get_number();

        printf("How many are legs?\n");
        num_legs = get_number();

        num_kame = tsurukame_checker(tsuru, kame, num_heads, num_legs);

        if (num_kame == -1){
            printf("This pair of the number of heads and legs is invalid.\n");
            printf("Please a correct number of heads and legs pair.\n");
        } else {
            printf("Number of Tsuru is %d.\n", num_heads - num_kame);
            printf("Number of Kame is %d.\n", num_kame);
        }
    }
    return 0;
}

