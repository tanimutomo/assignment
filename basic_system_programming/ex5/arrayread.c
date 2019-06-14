#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>


int main() {
    int a[100];
    int i, fd;
    fd = open("array.dat", O_RDONLY);
    read(fd, a, sizeof(int)*6);
    close(fd);
    for (i=0; i<6; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }
    exit(0);
}
