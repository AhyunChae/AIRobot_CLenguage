#include <stdio.h>

void print_line(void);

int main(void) {
  print_line();

  return 0;
}

void print_line(void) {
  int i;

  for (i=0; i<50; i++) {
    printf("-");
  }
  printf("\n");
}