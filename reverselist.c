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
LIST reverse(LIST L);

int main(int argc, char *argv[]){

  LIST L;
  int i;

  L = init_list();
  
  for(i=0; i<20; i++){
    insert_list(i, L);
  }

  print_list(L);
  L = reverse(L);
  print_list(L);
  
  delete_list(L);
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

void delete_list(LIST L){
  
  position tmp, p;
  p = L;
  while(p != NULL){
    tmp = p->next;
    free(p);
    p = tmp;
  }
}

LIST reverse(LIST L){

  position t, y;
  position r = NULL;

  y = L->next;  

  if(L == NULL){ //empty list
    printf("List is empty\n");
    exit(1);
  }
  if(L->next->next == NULL) //only one element
    return;

  while(y != NULL){
    t = y->next;
    y->next = r;
    r = y;
    y = t;   
  }
 
  L->next = r; 
  return L;
   
}




