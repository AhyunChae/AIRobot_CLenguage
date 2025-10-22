#include <stdio.h>

int main(void) {
  double mass, torque, gear, radius, SF, margin;
  int wheels;

  const double g = 9.81; // 중력 가속도
  const double c = 0.018; // 구름저항계수 - 일반적인 고무바퀴 & 아스팔트

  // 기획 단계
  printf("[기획 단계]\n");
  printf("구동 바퀴 수: ");
  if (scanf("%d", &wheels)!=1) return 1;
  printf("총 하중 (kg): ");
  if (scanf("%lf", &mass)!=1) return 1;
  printf("안전계수: ");
  if (scanf("%lf", &SF)!=1) return 1;
  printf("설계마진: ");
  if (scanf("%lf", &margin)!=1) return 1;

  while (1) {
    printf("\n[모터 정보]\n");
    printf("모터 정격 토크 (N*M): ");
    if (scanf("%lf", &torque)!=1) break;
    printf("감속비: ");
    if (scanf("%lf", &gear)!=1) break;
    printf("바퀴 반지름 (m): ");
    if (scanf("%lf", &radius)!=1) break;

    double W = mass * g;
    double F_min = c * W * SF * margin;
    double F_motor = (torque * gear / radius) * wheels;

    printf("\n필요한 최소 견인력 : %.2f [N]\n", F_min);
    printf("모터가 낼 수 있는 견인력 :%.2f [N]\n", F_motor);

    if (F_motor >= F_min) {
      printf("판정: 만족 (모터 견인력이 충분합니다.)\n");
    }
    else {
      printf("판정: 불만족 (더 큰 모터나 감속비가 필요.)\n");
    }
  }

  return 0;
}