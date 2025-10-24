#include <stdio.h>

int main(void) {
  int a, b;
  int *pa;

  a = 1;
  printf("변수형으로 a 값 출력: %d\n", a);
  
  b = a;
  a = 10;

  pa = &a;
  *pa = 10;

  /*
    1. pa라는 변수에 접근을 해요.
    2. pa는 포인터고, pa에 a 주소값이 저장되어 있었어요.
    3. pa에 저장되어 있던 a의 주소에 접근을 해요.
    4. 접근한 a에 10을 저장해요.
  */

  printf("포인터로 a 값 출력: %d\n", *pa);
  printf("변수형으로 a 값 출력: %d\n", a);


  return 0;
}