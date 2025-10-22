#include <stdio.h>

int main(void) {
  int a = 1;
  int i;

  for (printf("abcd\n"); i<3; i++) { // for문의 초기식은 무조건 한번 실행된다.
    a = a*2;
  }

  printf("a : %d\n", a);

  return 0;
}