#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 360 // scan의 길이
#define LN_MIN 10 // 최솟값 저장할 배열의 길이
#define MAX 500 // 랜덤으로 선언할 값의 최대값

int main(void) {
  double scan[LEN];
  int i, j;
  srand(time(NULL));

  printf("[");
  // 랜덤값 설정
  for (i=0; i<LEN; i++) {
    scan[i] = rand() % MAX + 1;
    printf("%d", (int)scan[i]);
    if (i != LEN-1) printf(", ");
  }
  printf("]\n\n");

  // 최솟값 탐색
  double min_n[LN_MIN];
  int min_d[LN_MIN];

  // 첫번째 최솟값 탐색
  min_d[0] = -1;
  min_n[0] = MAX+1;
  for (i=0; i<LEN; i++) {
    if (min_n[0] > scan[i]) {
      min_d[0] = i;
      min_n[0] = scan[i];
    }
  }

  // 두번째 부터 탐색
  for (i=1; i<LN_MIN; i++) {
    min_d[i] = -1;
    min_n[i] = MAX+1;

    for (j=0; j<LEN; j++) {
      if (min_n[i] > scan[j] && scan[j] > min_n[i-1]) {
        min_d[i] = j;
        min_n[i] = scan[j];
      }
    }

  }

  for (i=0; i<LN_MIN; i++) {
    printf("%d° : %.0lf (m)\n", min_d[i]+1, min_n[i]);
  }

  return 0;
}