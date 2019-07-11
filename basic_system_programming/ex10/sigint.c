#include <signal.h>
#include <sys/signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXCOMLEN 1024

int main(int argc, char *argv[]) {
  int comlen;
  char line[MAXCOMLEN];
  char command[MAXCOMLEN];
  struct sigaction act;

  act.sa_handler = SIG_IGN;
  sigemptyset(&act.sa_mask);
  act.sa_flags = 0;

  if(sigaction(SIGINT, &act, NULL) < 0) {
    perror("sigaction");
    exit(1);
  }

  for(;;) {
    fprintf(stderr, "myshell> ");
    if(fgets(line, MAXCOMLEN, stdin) == NULL) {
      break;
    } else {
      fprintf(stderr, "%s\n", command);
    }
  }
  exit(0);
}
