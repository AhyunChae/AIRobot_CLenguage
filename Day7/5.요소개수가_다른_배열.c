#include <stdio.h>

void print_ary(int *pa, int size);

int main(void) {
  int ary1[5] = { 10, 20, 30, 40, 50 };
  int ary2[7] = { 10, 20, 30, 40, 50, 60, 70 };

  int ary1_ln = sizeof(ary1) / sizeof(ary1[0]);
  int ary2_ln = sizeof(ary2) / sizeof(ary2[0]);

  print_ary(ary1, ary1_ln);
  print_ary(ary2, ary2_ln);

  return 0;
}

void print_ary(int *pa, int size) {
  int i;

  for (i=0; i<size; i++) {
    printf("%d ", pa[i]);
  }
  printf("\n");
}