#include <stdio.h>

int main(void) {
  float I_load = 8, vel = 6.4, R = 0.1;
  printf("----------사전 선정 정보----------\n");
  printf("평균전류 I_load [A] (부하측): %d\n", (int)I_load);
  printf("평균속도 vel [km/h]: %.1f\n", vel);
  printf("예비율 R [20%% = 0.2]: %.1f\n", R);
  printf("\n");

  float V = 24, C = 60, eta = 0.95;
  printf("-----------배텨리 정보-----------\n");
  printf("공칭전압 V [V]: %d\n", (int)V);
  printf("용량 C [Ah]: %d\n", (int)C);
  printf("시스템 효율 eta [90%% = 0.9]: %.2f\n", eta);

  float E, P, t, d;
  // 사용 가능 에너지(Wh)
  E = V * C * eta * (1-R);

  // 소비전력(W)
  P = (V * I_load) / eta;

  // 런타임(h)
  t = E / P;

  // 주행거리(km)
  d = vel * t;

  printf("\n");
  printf("[결과]\n");
  printf("사용 가능 에너지 E_usable : %.2f Wh\n", E);
  printf("런타임 t\t\t : %.2f h (%.1f min)\n", t, t*60);
  printf("주행거리 d\t\t : %.2f km\n", d);
  printf("(계산 가정: 전압강하/온도영향 무시, 평균전류 일정, 전류는 부하측 기준)\n");

  return 0;
}