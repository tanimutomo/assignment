#include <stdio.h>
#include <stdlib.h>

int intcmp(int *a, int *b) {
  if (*a > *b) {
    return (1);
  }
  if (*a < *b) {
    return (-1);
  }
  return (0);
}

main() {
  int d[10] = {3, 5, 7, 9, 8, 2, 4, 1, 0, 6};
  int i;
  qsort((char *)d, 10, sizeof(int), (void *)intcmp);
  for (i = 0; i < 10; i++) {
    printf("%d ", d[i]);
  }
  printf("\n");
}

