#include <stdio.h>

int *func(int a, int *x);

int main(void) {
  int i;
  int x = 10;
  int *p;
  int a[100];

  for (i=0; i<100; i++) {
    a[i] = i * 10;
  }

  p = func(x,a);
  printf("sum = %d\n", x + a[0] + a[1] + p[0] + p[1]);
  printf("x: %d, a[0]: %d, a[1]: %d, p[0]: %d, p[1]: %d\n", x, a[0], a[1], p[0], p[1]);

  return 0;
}

int *func(int a, int *x) {
  a = a + 10;
  x = x + 1;
  *x = *x * 2; // x가 a[1]부터 시작하므로, p[0]은 a[1]이다.

  return x;
}