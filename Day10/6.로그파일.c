#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_LEN 100

typedef struct node {
  char* data;
  Node* next;
}Node;

typedef struct block_list {
  Node* top;
  int len;
} BlockList;


BlockList* create_list(void);
void push_back(BlockList *list, char *str);

int main(void) {
  int i, j;
  const FILE *log;

  log = fopen("../battery-report-test.html", "r");
  if (log == NULL) {
    printf("파일을 읽지 못했습니다.");
    return 1;
  }

  FILE *fp = log;
  fseek(fp, 0, SEEK_END);
  long int size = ftell(fp);
  
  char buffer[BUFFER_LEN];
  char* target = strstr(buffer, "<td class=\"dateTime\">");
  BlockList* block = create_list();
  


  fclose(fp);
  return 0;
}

BlockList* create_list(void) {
  BlockList list;
  list.len = 1;

  return &list;
}

Node* find_tail(Node* node) {
  if (node->next == -1) {
    return node;
  }
  return find_tail(node->next);
}

void push_back(BlockList *list, char *str) {
  Node node;
  node.data = str;
  node.next = -1;

  if (list->len == 1) {
    list->top = &node;
  }
  else {
    Node* tail = find_tail(list->top);
    tail->next = &node;
  }
}