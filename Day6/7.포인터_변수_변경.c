#include <stdio.h>

int main(void) {
  int a = 10;
  int *pa = &a;

  printf("a: %d\n", *pa);
  *pa = 20;
  printf("a: %d\n", *pa);

  return 0;
}