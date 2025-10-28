#include <stdio.h>

struct profile {
  int age;
  double height;
};

struct student {
  struct profile pf;
  int id;
  double grade;
};



int main(void) {
  struct student s1 = {  };

  
  

  return 0;
}