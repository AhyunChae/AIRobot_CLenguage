#include <stdio.h>

#define LEN 10
#define BUMP 5

int main(void) {
  int bettery[LEN] = {60, 45, 32, 28, 33, 31, 40, 36, 29, 42};
  int flag[LEN];
  int i, gap;

  printf("%d%%: ", bettery[0]);
  flag[0] = 0;
  if (bettery[0] <= 30) {
    flag[0] = 1;
    printf("ON;  ");
  }
  else {
    printf("OFF;  ");
  }

  for (i=1; i<LEN; i++) {
    flag[i] = 0;
    if (bettery[i] <= 30) {
      flag[i] = 1;
    }
    else if (bettery[i] < 35) {
      if (flag[i-1]) {
        flag[i] = 1;
      }
    }

    printf("%d%%: ", bettery[i]);
    if (flag[i]) {
      printf("ON;  ");
    }
    else {
      printf("OFF;  ");
    }
  }
  printf("\n");


  return 0;
}