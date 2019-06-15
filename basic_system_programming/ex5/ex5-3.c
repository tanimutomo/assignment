#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define MAX_ITER 2048
#define SIZE 4


int main(int argc, char *argv[]) {
    // Exception Handling
    if (argc < 2) {
        printf("Please specify the filename which you want to check contents.\n");
        exit(1);
    }

    // Iteration for several arguments
    // for (int f = 1; f < argc; f++) {
    // Load the file
    int f = 1;
    int fd, res_read;
    fd = open(argv[f], O_RDONLY);
    if (fd == -1) {
        perror(argv[f]);
        exit(1);
    }

    // Read and write the contents of the file.
    for (int i = 0; i < MAX_ITER; i++) {
        int tmp[SIZE];
        res_read = read(fd, tmp, sizeof(int)*SIZE);
        if (res_read == 0) {
            exit(0);
        }
        write(1, tmp, sizeof(int)*SIZE);
    }
    close(fd);

    // }
    exit(0);
}
