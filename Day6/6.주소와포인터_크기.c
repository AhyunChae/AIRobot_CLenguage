#include <stdio.h>

int main(void) {
  char *ch;
  printf("char형 변수의 주소 크기: %d\n", sizeof(&ch));
  printf("char형 변수의 주소 크기: %d\n", sizeof(&ch));
  printf("char형 변수의 주소 크기: %d\n", sizeof(&ch));

  return 0;
}