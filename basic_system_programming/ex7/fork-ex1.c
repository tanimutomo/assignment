#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  pid_t pid;

  printf("Now, create new process \n");
  pid = fork();
  if (pid < 0) {
    printf("fork error\n");
    exit(1);
  }
  if (pid == 0) {
    printf("child's process id = %d\n", (int)getpid());
    sleep(10);
  } else {
    printf("parent's process id = %d\n", (int)getpid());
    sleep(10);
  }
  exit(0);
}
