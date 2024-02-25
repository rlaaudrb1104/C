#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode{
  element data;
  struct DListNode* llink;
  struct DListNode* rlink;
}DListNode;

void init(DListNode* phead){
  phead -> llink = phead;
  phead -> rlink = phead;
}
void print_dlist(DListNode* phead){
  DListNode* p;
  for (p = phead -> rlink; p != phead; p = p -> rlink){
    printf("<-||%d||->", p -> data);
  }
  printf("\n");
}
void add_node(DListNode* before, element data){
  DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
  newnode -> data = data;
  newnode -> llink = before;
  newnode -> rlink = before -> rlink;
  before -> rlink -> llink = newnode;
  before -> rlink = newnode;
  }


void remove_node(DListNode* head, DListNode* removed){
  if(removed == head) return;
  removed -> llink -> rlink = removed -> rlink;
  removed -> rlink -> llink = removed -> llink;
  free(removed);
}

DListNode* find_node(DListNode* head, element data){
  DListNode * current = head -> rlink;
  while(current != head){
    if(current -> data == data){
      return current;
    }
    current = current -> rlink;
  }
  return NULL;
}

int main(void){
  DListNode * head = (DListNode*)malloc(sizeof(DListNode));
  init(head);

  while(1){
  int num = 0;
  int node = 0;
  printf("1.추가\n2.제거\n3.종료\n");
  scanf("%d", &num);
  if(num == 1){
    printf("추가할 노드 입력:");
    scanf("%d", &node);
    add_node(head, node);
  }
  else if (num == 2) {
    printf("제거할 노드 입력:");
    scanf("%d", &node);
    DListNode* f_node = find_node(head, node);
    if(f_node != NULL){
      remove_node(head, f_node);
    }
    else {
      printf("일치하는 노드가 없습니다.\n");
    }

  }
  else if (num == 3){
    break;
  }
  else{
    printf("잘못된 입력입니다.\n");
  }
  print_dlist(head);
  
  }
  free(head);
  return 0;
}