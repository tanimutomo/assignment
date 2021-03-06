/*
 * Life game
 */

#include <stdio.h>
#include <stdlib.h>
#define process
#define N 22                             /* vertical */
#define M 78                             /* horizontal */
#define MAX_GEN 1000
char a[N + 2][M + 2], b[N + 2][M + 2];   /* board */
char c;

int main()
{
  int i, j, g;
  char x;

  /* initialization */
  board_init();

  for (g = 1; g <= MAX_GEN; g++) {
    /* printout current board */
    board_out(g);

    /* calculate the next generation */
    for (i = 0; i <= N + 1; i++) {
      for (j = 0; j <= M + 1; j++) {
         stone(i,j);    
      }
    }  
    usleep(400000);

  }
  return 0;
}


board_init()
{
  a[N/2][M/2] = 1;
  a[N/2][M/2+1] = 1;
  a[N/2][M/2+2] = 1;
  a[N/2][M/2+3] = 1;
  a[N/2-1][M/2+4] = 1;
  a[N/2+1][M/2] = 1;
  a[N/2+1][M/2+1] = 1;
  a[N/2+1][M/2+2] = 1;
  a[N/2+1][M/2+3] = 1;
  a[N/2+1][M/2+4] = 1;
}


board_out(gen)
int gen;
{
  int i, j;

  system("clear");                    /* quick hacking */ 
  printf("Generation %4d\n", gen);

  for (i = 1; i <= N; i++) {
    for (j = 1; j <= M; j++)
      if (a[i][j]) {
	  printf("*");
	  /* count up around cells */
	  b[i-1][j-1]++;  b[i-1][j]++;  b[i-1][j+1]++;
	  b[i  ][j-1]++;                b[i  ][j+1]++;
	  b[i+1][j-1]++;  b[i+1][j]++;  b[i+1][j+1]++;
      } else {
	  printf(".");
      }
      printf("\n");
    }		
}

process stone(i, j)
int i, j;
{
  if (b[i][j] != 2) {
      a[i][j] = (b[i][j] == 3);
  }
  b[i][j] = 0;
}



