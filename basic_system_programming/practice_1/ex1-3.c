#include <stdio.h>

int tsurukame_checker(int, int, int, int);

int main(){
    int tsuru, kame;
    tsuru = 2;
    kame = 4;

    int atama, ashi;
    atama = 10;
    ashi = 28;

    int num_kame;
    num_kame = tsurukame_checker(tsuru, kame, atama, ashi);

    if (num_kame == -1){
        printf("This pair of atama and ashi is not valid.\n");
    } else {
        printf("Number of Tsuru is %d.\n", atama - num_kame);
        printf("Number of Kame is %d.\n", num_kame);
    }
    return 0;
}


int tsurukame_checker(int tsuru, int kame, int atama, int ashi){
    for (int x = 0; x <= atama; x++){
        if (tsuru*(atama-x) + kame*x == ashi){
            return x;
        }
    }
    return -1;
}



