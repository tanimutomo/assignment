#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  pid_t pid;

  printf("Now, create new process \n");
  pid = fork();
  if (pid < 0) {
    perror("fork");
    exit(1);
  }
  if (pid == 0) {
    printf("child's process id = %d\n", (int)getpid());
    printf("Now execute ls command.\n");
    if (execl("ls", "ls", (char *)NULL) < 0) {
      perror("execl");
      exit(1);
    }
  } else {
    printf("parent's process id = %d\n", (int)getpid());
    printf("parent process terminated.\n");
    exit(0);
  }
  exit(0);
}
