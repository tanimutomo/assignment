#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int charcmp(char *a, char *b) {
  return strcmp(a, b);
}

int main() {
  char words[20][20] = {
      "training", 
      "model", 
      "learn",
      "expectation",
      "data",
      "machine",
      "adversarial",
      "robust",
      "perception",
      "network",
      "representation",
      "feature",
      "pertubation",
      "generative",
      "connection",
      "classification",
      "distribution",
      "accuracy",
      "bound",
      "norm"
  };

  int i;
  qsort((void *)words, 20, sizeof(words[0]), (void *)charcmp);
  for (i = 0; i < 20; i++) {
    printf("%s ", words[i]);
  }
  printf("\n");
}

