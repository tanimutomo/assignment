#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define MAX_ITER 2048
#define SIZE 128


int main(int argc, char *argv[]) {
  // Exception Handling
  if (argc < 2) {
    printf("Please specify the filename which you want to check contents.\n");
    exit(1);
  }

  // Load the reading file
  int f = 1;
  int fd, res_read;
  fd = open(argv[f], O_RDONLY);
  if (fd == -1) {
    perror(argv[f]);
    exit(1);
  }

  // Define base file name
  char *filename = "out_f_";
  char out_f[30];

  // Create and Open the output file
  int fd_out, f_count = 0;
  sprintf(out_f, "%s%d", filename, f_count);
  fd_out = open(out_f, O_WRONLY|O_CREAT, 0700);

  // Read and Write the contents of the file.
  int count = 0;
  for (int i = 0; i < MAX_ITER; i++) {
    int content[SIZE];
    res_read = read(fd, content, sizeof(int)*SIZE);
    count += res_read;
    printf("%d\n", res_read);
    if (res_read == 0) {
      break;
    }
    write(fd_out, content, res_read);
  }
  close(fd);
  close(fd_out);

  exit(0);
}
