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
void delet_middle(position ptr);

int main(int argc, char *argv[]){

  LIST L;
  int i;
  int cnt = 0;
  position tmp;

  L = init_list();
  for(i=0; i<20; i++)
    insert_list(random(100), L);
    
  print_list(L);
  
  tmp = L->next;
  for(i=0; i<10; i++)
    tmp = tmp->next;
  
  delet_middle(tmp);
  print_list(L);
  
  delet_list(L);

  return 0; 
}

LIST init_list(){

  LIST L;
 
  L =(position)malloc(sizeof(struct node));

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
    printf("malloc new node error\n");
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
  while(tmp != NULL){
    tmp = p->next;
    free(p);
    p = tmp;  
  }
}

void delet_middle(position ptr){

  position tmp;

  if((ptr == NULL)||(ptr->next == NULL)){
    printf("empty node\n");
    exit(1);
  } 

  tmp = ptr->next;
  ptr->element = tmp->element;
  ptr->next = tmp->next;
  free(tmp);   
}




