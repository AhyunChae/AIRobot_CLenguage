#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 500
#define MIN 10

int main(void) {
  srand(100);

  int i, j, flag, count, num;
  int velocity[LEN];

  velocity[0] = LEN / 2;

  i = 1;
  while (i<LEN) {
    flag = rand() % 2; // 1: 가속, 0: 감속
    count = rand() % 5 + MIN; // 10 ~ 20

    printf("flag: %d, count: %d\n", flag, count);
    for (j=0; j<count; j++) {
      if (flag) velocity[i] = velocity[i-1] + 1;
      else velocity[i] = velocity[i-1] -1;
        
      printf("%d: %d;  ", j+1, velocity[i]);
      i++;
      if (i>=LEN) break;
    }
    printf("\n\n");
  }

  return 0;
}