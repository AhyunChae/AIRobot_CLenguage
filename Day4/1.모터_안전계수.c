#include <stdio.h>
#include <math.h>

void check_scan(char *str, double *d);

int main(void) {
  int flag = 0;
  double m, T_m, N_m, G, eta, r, c, SF;
  const double g = 9.81;

  check_scan("총 질량 [kg]", &m);
  check_scan("모터 정격토크 [N.m]", &T_m);
  check_scan("구동 모터 수 [개]", &N_m);
  check_scan("감속비", &G);
  check_scan("구동 효율 (0~1)", &eta);
  check_scan("바퀴 반지름 [m]", &r);
  check_scan("구름계수", &c);
  check_scan("안전계수 SF", &SF);

  double F_avail = (N_m * T_m * g) / r;
  double F_nead = sin(m * g) + c * m * G;
  printf("%.2f", F_avail);

  return 0;
}

void check_scan(char *str, double *d) {
  while (1) {
    printf("%-40s: ", str);
    if (scanf("%lf", d) == 1) break;
    else {
      while (getchar() != '\n' && !feof(stdin));
      continue;
    }
  }
}