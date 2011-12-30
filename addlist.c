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
void add_lists(LIST L1, LIST L2);

int main(int argc, char *argv[]){

  LIST L1, L2;
  int i;

  L1 = init_list();
  L2 = init_list();
 
  for(i=0; i<3; i++){
    insert_list(random(10), L1);
    insert_list(random(10), L2);
  } 

  print_list(L1);
  print_list(L2);
  add_lists(L1, L2);
  print_list(L2);

  delet_list(L1);
  delet_list(L2);
  
}

LIST init_list(){

  LIST L;

  L = (position)malloc(sizeof(struct node));
  if(L == NULL){
    printf("init list malloc error\n");
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

void add_lists(LIST L1, LIST L2){

  position tmp1, tmp2;
  int carry = 0;

  if((L1 == NULL)||(L2 == NULL)){
    printf("empty list\n");
    exit(1);
  }
  tmp1 = L1->next;
  tmp2 = L2->next;
  
  while((tmp1 != NULL)||(tmp2 != NULL)){
  if((tmp1 != NULL)&&(tmp2 != NULL)){
    tmp2->element = tmp1->element + tmp2->element + carry;
    if(tmp2->element >= 10){
      tmp2->element = tmp2->element % 10;
      carry = 1;
    }
    else{
      carry = 0;
    }
    tmp1 = tmp1->next;
    tmp2 = tmp2->next;
  }
  }

  
}
