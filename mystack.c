#include <stdio.h>
#include <stdlib.h>


typedef struct node *node_ptr;

struct node{

  void* element;
  node_ptr next;
};

typedef node_ptr STACK;

STACK creat_stack();
void push(int *x, STACK S);
int is_empty(STACK S);
int top(STACK S);
void pop(STACK S);

int main(int argc, char *argv[]){
  
  int i;
  STACK S;
  node_ptr tmp, start;
  int l;
 
  S = creat_stack();

  int array[20];

  int *p;
  p = (int *)malloc(sizeof(int));
  *p = 15;
  
  int *q;
  q = (int *)malloc(sizeof(int));
  *q = 16;

 
  for(i=0; i<20; i++)
    array[i] = i;
  for(i=0; i<10; i++){
    tmp = (node_ptr)malloc(sizeof(struct node));
    tmp->element = &array[i];
    tmp->next = S->next;
    S->next = tmp;  
  }
 
  push(p, S);
  //push(q, S); 
    
  for(start=S->next; start!= NULL; start = start->next){
    printf("%d\t", *((int *)start->element));
  }
  printf("\n");
  
  l = top(S);
  printf("%d\n", l);

  free(p);
  free(q);
  p = NULL;
  q = NULL;

  return 0; 
}


int is_empty(STACK S){

  return(S->next == NULL);

}

int top(STACK S){

  if(is_empty(S)){
    printf("empty stack\n");
    exit(1);
  }
  else
    return *((int *)S->next->element);
}
STACK creat_stack(){

  STACK S;
  S = (STACK)malloc(sizeof(struct node));
  if(S == NULL){
    printf("creat stack failed\n");
    exit(1);
  }

  return S;
}

void push(int *x, STACK S){

  node_ptr tmp_cell;
  
  tmp_cell = (node_ptr)malloc(sizeof(struct node));
  if(tmp_cell == NULL){
    printf("push failed\n");
    exit(1);
  }
  else{
    tmp_cell->element = x;
    tmp_cell->next = S->next;
    S->next = tmp_cell;
  }
}

void pop(STACK S){

  node_ptr first_cell;
  
  if(is_empty(S)){
    printf("empty stack\n");
    exit(1);
  }
  else{
    first_cell = S->next;
    S->next = S->next->next;
    free(first_cell);
  }
}
