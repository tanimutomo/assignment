#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define MAX_ITER 2048
#define SIZE 128


int main(int argc, char *argv[]) {
  // Exception Handling
  if (argc == 2) {
    printf("Please specify the bytes of a output file and the filename which you want to check contents.\n");
    exit(1);
  }

  // Check the arguments
  printf("%s, %s, %s\n", argv[0], argv[1], argv[2]);
  int idx_byte;
  if (argv[1][0] == '-') {
    idx_byte = 1;
  } else {
    idx_byte = 2;
  }

  // Get the byte of seprated files
  // char sep_byte_str[sizeof(argv[idx_byte])];
  // for (int i = 1; i < sizeof(argv[idx_byte]); i++) {
  //   sep_byte_str[i-1] = argv[idx_byte][i];
  //   if (argv[idx_byte][i] == '\0') {
  //     break;
  //   }
  //   // printf("%d: %c, ", i, sep_byte_str[i-1]);
  // }
  int sep_byte = atoi(++argv[idx_byte]);
  printf("%d\n", sep_byte);

  // Load the reading file
  int idx_file = idx_byte % 2 + 1;
  int fd_in, res_read;
  fd_in = open(argv[idx_file], O_RDONLY);
  if (fd_in == -1) {
    perror(argv[idx_file]);
    exit(1);
  }

  // Define base file name
  char *filename = "out_f_";
  char out_f[30];
  int fd_out;
  int size = (float) sep_byte / (float) sizeof(int);
  int content[size];

  for (int f_count = 0;;f_count++) {
    // Create and Open the output file
    sprintf(out_f, "%s%s%d", argv[idx_file], ".part", f_count);
    fd_out = open(out_f, O_WRONLY|O_CREAT, 0700);

    // Read and Write the contents of the file.
    res_read = read(fd_in, content, sep_byte);
    write(fd_out, content, res_read);
    // printf("res_read: %d\n", res_read);
    if (res_read < sep_byte) {
      break;
    }
    close(fd_out);
  }
  close(fd_in);
  exit(0);
}
