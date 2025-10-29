#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void) {
  const FILE *log;

  log = fopen("../battery-report-test.html", "r");
  if (log == NULL) {
    printf("파일을 읽지 못했습니다.");
    return 1;
  }

  FILE *fp = log;
  fseek(fp, 0, SEEK_END);
  long int size = ftell(fp);
  char* target = strstr(fp, "<td class=\"dateTime\">");
  


  fclose(fp);
  return 0;
}

