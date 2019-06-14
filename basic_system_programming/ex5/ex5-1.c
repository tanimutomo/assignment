#include <stdio.h>
#include <stdlib.h>


int tsurukame_checker(int tsuru, int kame, int atama, int ashi){
    for (int x = 0; x <= atama; x++){
        if (tsuru*(atama-x) + kame*x == ashi){
            return x;
        }
    }
    return -1;
}


int main(int argc, char *argv[]) {
    int tsuru, kame, num_kame;
    tsuru = 2;
    kame = 4;

    int num_heads, num_legs;
    if (argc == 3) {
        num_heads = atoi(argv[1]);
        num_legs = atoi(argv[2]);
    } else {
        printf("Please input only the number of heads and legs\n");
        exit(0);
    }

    num_kame = tsurukame_checker(tsuru, kame, num_heads, num_legs);

    if (num_kame == -1){
        printf("This pair of the number of heads and legs is invalid.\n");
        printf("Please a correct number of heads and legs pair.\n");
    } else {
        printf("Number of Tsuru is %d.\n", num_heads - num_kame);
        printf("Number of Kame is %d.\n", num_kame);
    }
    return 0;
}

