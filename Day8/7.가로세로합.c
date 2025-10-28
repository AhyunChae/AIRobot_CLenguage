#include <stdio.h>

#define ROW 5
#define COL 6

int main(void) {
  int row1[ROW], row2[ROW], row3[ROW], row4[ROW], row5[ROW], row6[ROW];
  int *arr[COL] = { row1, row2, row3, row4, row5, row6 };
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

  // 합 구하기
  for (i=0; i<ROW-1; i++) {

    for (j=0; j<COL-1; j++) {
      arr[i][COL-1] += arr[i][j]; // 행의 합
      arr[ROW-1][j] += arr[i][j]; // 열의 합
    }

  }

  // 검증
  for (i=0; i<ROW-1; i++) {
    arr[ROW-1][COL-1] += arr[i][COL-1];
  }
  i = 0; // 임시 변수
  for (j=0; j<COL-1; j++) {
    i += arr[ROW-1][j];
  }

  printf("행의 합: %d, 열의 합: %d\n\n", arr[ROW-1][COL-1], i);

  for (i=0; i<ROW; i++) {

    for (j=0; j<COL; j++) {
      printf("%d\t", arr[i][j]);
    }

    printf("\n");
  }

  return 0;
}