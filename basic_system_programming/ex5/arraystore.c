#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>


int main() {
    int a[6] = {2, 3, 5, 8, 13, 21};
    int len, fd;
    fd = open("array.dat", O_WRONLY|O_CREAT, 0644);
    len = sizeof(a);
    write(fd, a, len);
    close(fd);
    exit(0);
}
