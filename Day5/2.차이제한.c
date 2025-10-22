#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 10
#define BUMP 10
#define MAX 1000

int main(void) {
  srand(time(NULL));

  int i, temp;
  int velocity[LEN];

  // 속도 랜덤으로 설정
  velocity[0] = rand() % (MAX - BUMP*2) + 1;
  printf("[%d", velocity[0]);
  for (i=1; i<LEN; i++) {
    temp = velocity[i-1] + (rand() % (BUMP*2) - BUMP);
    if (temp < 0) { // 0보다 작은 경우 되돌아감
      i--;
      continue;
    }

    velocity[i] = temp;
    printf("%d", velocity[i]);
    if (i<LEN-1) printf(", ");
  }
  printf("]\n");

  return 0;
}