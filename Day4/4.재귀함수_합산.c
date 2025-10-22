#include <stdio.h>

int sum(int n);

int main(void) {
  printf("%d\n", sum(9));
  return 0;
}

int sum(int n) {
  int res = 0;
  if (n == 0) return res;
  res = n + sum(n-1);
  return res;
}