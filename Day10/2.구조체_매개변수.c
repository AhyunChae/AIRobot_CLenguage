#include <stdio.h>

struct vision {
  double left;
  double right;
};

struct vision exchange(struct vision robot);

int main(void) {
  struct vision robot1 = {1.0, 2.0};

  printf("left: %.1lf, right: %.1lf\n", robot1.left, robot1.right);
  robot1 = exchange(robot1);
  printf("left: %.1lf, right: %.1lf\n", robot1.left, robot1.right);

  return 0;
}

struct vision exchange(struct vision robot) {
  double temp;
  
  temp = robot.left;
  robot.left = robot.right;
  robot.right = temp;

  return robot;
}