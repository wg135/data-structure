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
void delete_list(LIST L);
void delete1(LIST L, position p);

int main(int argc, char *argv[]){

  LIST L;
  int i;
  position p;

  L = init_list();
  for(i=0; i<20; i++)
    insert_list(random(200), L);

  print_list(L);
  p = L->next;
  for(i=0; i<5; i++)
    p = p->next;
  delete1(L, p);
  print_list(L);
  delete_list(L);

  return 0;
}

LIST init_list(){

  LIST L;
  
  L = (LIST)malloc(sizeof(struct node));
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

void delete_list(LIST L){

  position tmp, p;
  p = L;
  while(p != NULL){
    tmp = p->next;
    free(p);
    p = tmp;
  }
}

void delete1(LIST L, position p){

  position tmp;

  if(p->next == NULL){ //p is last node
    tmp = p;
    free(tmp);
    p = NULL;
  }
  else{ // p is not last node
  tmp = p->next;
  p->element = tmp->element;
  p->next = p->next->next;
  free(tmp);
  }
}
