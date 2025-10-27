#include <stdio.h>

#define ROW 5
#define COL 6

int main(void) {
  int arr[ROW][COL];
  int i, j, count = 1;

  // 초기화
  for (i=0; i<ROW; i++) {
    for (j=0; j<COL; j++) {

      if (i < ROW-1 && j < COL-1) {
        arr[i][j] = count;
        count++;
      }
      else {
        arr[i][j] = 0;
      }

    }
  }

  // 행의 합 구하기
  int *sum;
  for (i=0; i<ROW-1; i++) {
    sum = &arr[i][COL-1];

    for (j=0; j<COL-1; j++) {
      *sum += arr[i][j];
    }

  }
  // 열의 합 구하기
  for (j=0; j<COL-1; j++) {
    sum = &arr[ROW-1][j];

    for (i=0; i<ROW-1; i++) {
      *sum += arr[i][j];
    }

  }
  // 검증
  sum = &arr[ROW-1][COL-1];
  for (i=0; i<ROW-1; i++) {
    *sum += arr[i][COL-1];
  }
  i = 0; // 임시 변수
  for (j=0; j<COL-1; j++) {
    i += arr[ROW-1][j];
  }

  printf("행의 합: %d, 열의 합: %d\n\n", *sum, i);

  for (i=0; i<ROW; i++) {

    for (j=0; j<COL; j++) {
      printf("%d\t", arr[i][j]);
    }

    printf("\n");
  }

  return 0;
}