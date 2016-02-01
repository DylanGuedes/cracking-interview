#include <stdio.h>
#include <string.h>

int solve(int arr[10][10])
{
  int i, j;
  int rows[10];
  int cols[10];

  memset(rows, 0, sizeof rows);
  memset(cols, 0, sizeof cols);

  for(i=0; i < 10; ++i) {
    for(j=0; j < 10; ++j) {
      if(arr[i][j] == 0) {
        cols[j] = 1;
        rows[i] = 1;
      }
    }
  }

  for(i=0; i < 10; ++i) {
    if(rows[i] == 1) {
      for(j=0; j < 10; ++j) {
        arr[i][j] = 0;
      }
    }
  }

  for(i=0; i < 10; ++i) {
    if(cols[i] == 1) {
      for(j=0; j < 10; ++j) {
        arr[j][i] = 0;
      }
    }
  }
}

int main(int argc, char const *argv[])
{
  int arr[10][10];
  int i, j;
  for(i=0; i < 10; ++i) {
    for(j=0; j < 10; ++j) {
      printf("[%d][%d]: ", i, j);
      scanf("%d", &arr[i][j]);
    }
  }

  solve(arr);

  for(i=0; i < 10; ++i) {
    for(j=0; j < 10; ++j) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }


  return 0;
}
