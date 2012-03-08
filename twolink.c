#include <stdio.h>
#include <stdlib.h>

typedef struct node *node_ptr;
typedef int element_type;

struct node{

  element_type element;
  node_ptr next;
};

typedef node_ptr LIST;
typedef node_ptr position;

LIST init_list();
void insert_list(element_type element, LIST L);
void print_list(LIST L);
void delet_list(LIST L);
void switchtwo(LIST L);

int main(int argc, char *argv[]){

  int i;
  LIST L;
  
  L = init_list();

  for(i=1; i<6; i++)
    insert_list(i, L);

  print_list(L);
  switchtwo(L);
  print_list(L);
  delet_list(L);
}

LIST init_list(){

  LIST L;

  L =(position)malloc(sizeof(struct node));
  if(L == NULL){
    printf("init list malloc error\n");
    exit(1);
  }
}

void insert_list(element_type element, LIST L){

  position tmp;

  tmp = (position)malloc(sizeof(struct node));
  if(tmp == NULL){
    printf("new node malloc error\n");
    exit(1);
  }
  else{
    tmp->element = element;
    tmp->next = L->next;
    L->next = tmp;
  }
}

void print_list(LIST L){

  position tmp;
  
  tmp = L->next;
  while(tmp != NULL){
    printf("%d ", tmp->element);
    tmp = tmp->next;
  }
  printf("\n");
}

void delet_list(LIST L){
    
  position tmp, p;
  
  p = L;
  while(p != NULL){
    tmp = p->next;
    free(p);
    p = tmp;
  }
}

void switchtwo(LIST L){

  position tmp1, tmp2;
  element_type tmp;

  tmp1 = L->next;
  if(L == NULL){
    printf("empty list\n");
    return;
  }
  if(tmp1->next == NULL)
  return;
  
  tmp2 = tmp1->next;
  while(tmp2 != NULL){
    tmp = tmp1->element;
    tmp1->element = tmp2->element;
    tmp2->element = tmp;
    
    tmp1 = tmp2->next;
    tmp2 = tmp1->next;
  }

  
  
}



