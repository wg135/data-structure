#include <stdio.h>
#include <stdlib.h>

#define random(x) (rand()%x)

typedef struct node *node_ptr;
typedef int element_type;

struct node{

  node_ptr prev;
  element_type element;
  node_ptr next;
};

typedef node_ptr LIST;
typedef node_ptr position;

position new_node(element_type element);
position insert(element_type element, position p);
void print_double_list(LIST L);
void free_double_list(LIST L);
LIST init_double_list(element_type array[], int len);// L =insert(L>next);

position new_node(element_type element){

  position p = (position)malloc(sizeof(struct node));
  if(p == NULL){
    printf("new malloc error\n");
    exit(1);
  }
  else{
    p->element = element;
    p->prev = NULL;
    p->next = NULL;
  }
  return p;
}

position insert(element_type element, position p){

  position tmp;
  
  if(p == NULL)
    return new_node(element);
  else{
    tmp = new_node(element);
    tmp->prev = p;
    p->next = tmp;
    tmp->next = NULL;
  }

  return tmp;  
}

LIST init_double_list(element_type array[], int len){

  LIST L;
  int i;
  position p;

  if(len <= 0)
    exit(1);

  L = insert(array[0], NULL);   
  p = L;

  for(i=1; i<len; i++)
    p = insert(array[i], p);

  return L;
}

void print_double_list(LIST L){
  position p;
  
  p = L;
  while(p != NULL){
    printf("%d ", p->element);
    p = p->next;
  }
  printf("\n");
}

void free_double_list(LIST L){

  position tmp, p;
  
  p = L;
  while(p != NULL){
    tmp = p->next;
    free(p);
    p = tmp;
  }
   
}


