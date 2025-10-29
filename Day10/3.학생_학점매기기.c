#include <stdio.h>
#include <stdlib.h>

typedef struct score {
  int sum;
  double average;
  char grade;
} Score;

typedef struct student {
  char name[10];
  int korean;
  int english;
  int math;
  Score grade;
} Student;

void get_score(Student *student, int len);
void sort(Student *student, int len);

int main(void) {
  int i, len;
  Student *student;

  printf("학생 수: ");
  scanf("%d", &len);
  student = (Student *)malloc(sizeof(Student) * len);

  for (i=0; i<len; i++) {
    printf("%d:\n", i+1);
    scanf("%s%d%d%d", student[i].name, &student[i].korean, &student[i].english, &student[i].math);
    printf("\n");
  }

  get_score(student, len); // 배열은 원래 주소니까 &가 없어도 된다
  sort(student, len);

  Score st;
  for (i=0; i<len; i++) {
    st = student[i].grade;
    printf("%s -  총점: %d, 평균: %.1f, 학점: %c\n", student[i].name, st.sum, st.average, st.grade);
  }

  free(student);
  return 0;
}

void get_score(Student *student, int len) {
  int i;
  Score *st;
  for (i=0; i<len; i++) {
    st = &student[i].grade;
    st->sum = student[i].korean + student[i].english + student[i].math;
    st->average = st->sum / 3;

    if (st->average >= 90) {
      st->grade = 'A';
    }
    else if (st->average >= 80) {
      st->grade = 'B';
    }
    else if (st->average >= 70) {
      st->grade = 'C';
    }
    else {
      st->grade = 'F';
    }
  }
}

void sort(Student *student, int len) {
  int i, j, max_id;
  Student temp;
  for (i=0; i<len-1; i++) {
    max_id = i;

    for (j=i+1; j<len; j++) {
      if (student[max_id].grade.sum < student[j].grade.sum) {
        max_id = j;
      }
    }

    if (i == max_id) continue;
    temp = student[max_id];
    student[max_id] = student[i];
    student[i] = temp;
  }
}