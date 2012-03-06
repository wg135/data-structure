#include <stdio.h>
#include <stdlib.h>

#define random(x) (rand()%x)

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
void union_check(LIST L1, LIST L2);

int main(int argc, char *argv[]){

  int i;
  LIST  L1, L2, L3;
  position tmp1, tmp2, tmp3;
  
  L1 = init_list();
  L2 = init_list();
  L3 = init_list();

  for(i=0; i<10; i++)
    insert_list(1, L1);

  for(i=0; i<10; i++)
    insert_list(2, L2);

  for(i=0; i<10; i++)
    insert_list(3, L3);
  
  tmp3 = L3->next;
 
  tmp1 = L1;
  tmp2 = L2; 
  for(i=0; i<10; i++){
    tmp1 = tmp1->next;
    tmp2 = tmp2->next;
  }  

  tmp1->next = tmp3;
  tmp2->next = tmp3;
  print_list(L1);
  print_list(L2);

  union_check(L1, L2);

  delet_list(L1);
  delet_list(L2);
}

LIST init_list(){

  LIST L;
 
  L = (position)malloc(sizeof(struct node));
  if(L == NULL){
    printf("inti list malloc error\n");
    exit(1);
  }
  else
    L->next = NULL;
  
  return L;
}

void insert_list(element_type element, LIST L){

  position tmp;

  tmp = (position)malloc(sizeof(struct node));
  if(tmp == NULL){
    printf("new mode malloc error\n");
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

void union_check(LIST L1, LIST L2){
  
  position tmp1, tmp2;
 
  if((L1->next == NULL)||(L2->next == NULL)){
    printf("empty list\n");
    exit(1);
  }

  tmp1 = L1;
  tmp2 = L2; 
  while(tmp1->next != NULL){
    tmp1 = tmp1->next;
  }
  while(tmp2->next != NULL){
    tmp2 = tmp2->next;
  }
  
  if(tmp1 == tmp2){
    printf("L1 and L2 are union\n");
  }
  else
    printf("L1 and L2 are not union\n");
}
