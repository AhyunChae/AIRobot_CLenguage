#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_LEN 200

typedef struct node {
  char* data;
  int idx;

  struct node* front;
  struct node* next;
}Node;
Node* find_tail(Node* node) {
  if (node->next == NULL) {
    return node;
  }
  return find_tail(node->next);
}

typedef struct block_list {
  Node* top;
  int len;
} BlockList;
BlockList* create_list(void) {
  BlockList *list = (BlockList *)malloc(sizeof(BlockList));
  if (list == NULL) return NULL;
  list->len = 0;

  return list;
}
void print_all_list(Node* node) {
  if (node == NULL) return;
  printf("%s\n", node->data);
  printf("--------------------------------------------------------------------------------------------------\n");
  print_all_list(node->next);
}

void push_back(BlockList *list, char *str);
void free_list(BlockList* list);

int main(void) {
  int i, j;
  FILE *fp;

  fp = fopen("../battery-report-test.html", "r");
  if (fp == NULL) {
    printf("파일을 읽지 못했습니다.");
    return 1;
  }

  fseek(fp, 0, SEEK_END);
  long int size = ftell(fp);
  fseek(fp, 0, SEEK_SET);
  
  BlockList* block = create_list();
  char* target;

  // 블록 분리
  char buffer[BUFFER_LEN];
  char* buff_str = (char*)malloc(size/2); // 힙 영역에 저장
  long int found_str;
  while (fgets(buffer, BUFFER_LEN, fp) != NULL) {
    target = strstr(buffer, "-");

    if (target != NULL) {
      found_str = strlen(target);
      strncat(buff_str, target, found_str);

      push_back(block, buff_str); // target을 찾을때만 노드 추가
      buff_str = (char*)malloc(size);
    }
    else {
      strcat(buff_str, buffer);
    }
  }
  
  print_all_list(block->top);
  printf("%d\n", block->len);

  // Node* day = search_str(block->top, "-"); // 날짜가 시작되는 데이터
  // char* end_percent = strstr((*day).data, "<td class=\"percent\">");

  free(buff_str);
  free_list(block);
  fclose(fp);
  return 0;
}

Node* search_str(Node* node, char* str) {
  char* found = strstr(node->data, str);
    if (found == NULL) {
    return search_str(node->next, str);
  }
  return node;
}

void push_back(BlockList* list, char* str) {
  Node *node = (Node*)malloc(sizeof(Node));
  node->data = (char*)malloc(strlen(str)+1);
  strncpy(node->data, str, strlen(str)+1);
  node->next = NULL;

  if ((*list).len == 0) {
    node->idx = 0;
    node->front = NULL;
    list->top = node;
    list->len += 1;
  }
  else {
    Node* tail = find_tail(list->top);
    node->front = tail;
    tail->next = node;

    node->idx = tail->idx + 1;
    list->len += 1;
  }
}

void free_list(BlockList* list) {
    if (list == NULL) {
        return;
    }

    Node *current = list->top;
    Node *next_node;

    while (current != NULL) {
        next_node = current->next;
        if (current->data != NULL) free(current->data);
        free(current);
        current = next_node;
    }
    free(list);
}