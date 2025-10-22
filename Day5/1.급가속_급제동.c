#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 10
#define MAX 200

int main(void) {
  srand(time(NULL));

  int i, rapid_accel = 0, sudden_brake = 0;
  int velocity[LEN];

  // 속도 랜덤으로 설정
  printf("[");
  for (i=1; i<LEN; i++) {
    velocity[i] = rand() % MAX +1;
    printf("%d", velocity[i]);
    
    if (i<LEN-1) printf(", ");
  }
  printf("]\n");

  for (i=1; i<LEN; i++) {
    int gap = velocity[i] - velocity[i-1];

    if (gap >= 10) {
      rapid_accel++;
    }
    else if (gap <= -10) {
      sudden_brake++;
    }
  }
  
  printf("\n급가속: %d, 급제동: %d\n", rapid_accel, sudden_brake);

  return 0;
}