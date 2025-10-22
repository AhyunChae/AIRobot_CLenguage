#include <stdio.h>

int main(void) {
  int i, j;

  // for문
  // for (i=2; i<10; i++) {
  //   for (j=1; j<10; j++) {
  //     printf("%d * %d = %d\n", i, j, i*j);
  //   }
  //   printf("\n");
  // }

  // while문
  // i = 2;
  // while (i<10) {
  //   j = 1;
  //   while (j<10) {
  //     printf("%d * %d = %d\n", i, j, i*j);
  //     j++;
  //   }
  //   printf("\n");
  //   i++;
  // }

  // do while문
  i = 2;
  do {
    j = 1;
    do {
      printf("%d * %d = %d\n", i, j, i*j);
      j++;
    } while (j < 10);

    printf("\n");
    i++;

  } while (i < 10);

  return 0;
}