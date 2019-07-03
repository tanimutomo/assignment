#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

extern int errno;

#define MAXCOMLEN 1024

int main(int argc, char *argv[], char *envp[]) {
  char line[MAXCOMLEN];
  char command[MAXCOMLEN];
  int comlen;
  pid_t pid;

  for (;;) {
    fprintf(stderr, "tinyshell> ");
    fgets(line, MAXCOMLEN, stdin);
    comlen = strlen(line);
    strncpy(command, line, comlen-1);
    command[comlen-1] = '\0';

    if (strcmp(command, "bye") == 0) {
      fprintf(stderr, "exiting.\n");
      break;
    }
    pid = fork();
    if (pid == 0) {
      if (execl(command, command, (char *) NULL) < 0) {
        perror("execl");
        exit(-1);
      }
    } else {
      // pid_t wait(int *stat_loc);
      fprintf(stderr, "fork pid=%d\n", (int)pid);
    }
  }
  exit(0);
}
