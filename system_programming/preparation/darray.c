#include<stdio.h>

int main(void) {
    // 2d array
    int kuku[9][9];

    // calcurate
    kuku[0][0] = 1 * 1;
    kuku[0][1] = 1 * 2;
    kuku[0][2] = 1 * 3;
    kuku[0][3] = 1 * 4;
    kuku[0][4] = 1 * 5;
    kuku[0][5] = 1 * 6;
    kuku[0][6] = 1 * 7;
    kuku[0][7] = 1 * 8;
    kuku[0][8] = 1 * 9;

    kuku[1][0] = 2 * 1;
    kuku[1][1] = 2 * 2;
    kuku[1][2] = 2 * 3;
    kuku[1][3] = 2 * 4;
    kuku[1][4] = 2 * 5;
    kuku[1][5] = 2 * 6;
    kuku[1][6] = 2 * 7;
    kuku[1][7] = 2 * 8;
    kuku[1][8] = 2 * 9;

    // output
    printf("%d, %d, %d, %d, %d, %d, %d, %d, %d\n",
        kuku[0][0], kuku[0][1], kuku[0][2],
        kuku[0][3], kuku[0][4], kuku[0][5],
        kuku[0][6], kuku[0][7], kuku[0][8]);
    printf("%d, %d, %d, %d, %d, %d, %d, %d, %d\n",
        kuku[1][0], kuku[1][1], kuku[1][2],
        kuku[1][3], kuku[1][4], kuku[1][5],
        kuku[1][6], kuku[1][7], kuku[1][8]);

    return 0;
}

