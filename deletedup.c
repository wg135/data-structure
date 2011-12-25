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

int is_list_empty(LIST L);
position init_list();
void insert(element_type x, LIST L);
void print_list(LIST L);
void delet_list(LIST L);
void delet_dup(LIST L);


int main(int argc, char *argv[]){

  LIST L;
  int i;

  L = init_list();
  for(i=0; i<20; i++)
    insert(random(30), L);

  print_list(L);
  delet_dup(L);
  print_list(L);
  delet_list(L);
  
  return 0;  
}

int is_list_empty(LIST L){

  return (L->next == NULL);
}

position init_list(){

  LIST L = (position)malloc(sizeof(struct node));
  if(L == NULL){
    printf("init list error\n");
    exit(1);
  }
  
  L->next = NULL;

  return L;
}

void insert(element_type x, LIST L){

  position tmp_cell;

  tmp_cell = (position)malloc(sizeof(struct node));
  if(tmp_cell == NULL){
    printf("insert malloc error\n");
    exit(1);
  }
  else{
    tmp_cell->element = x;
    tmp_cell->next = L->next;
    L->next = tmp_cell;
  }
  
}

void print_list(LIST L){

  position l;
  int i;

  for(l = L->next; l != NULL; l = l->next)
    printf("%d ", l->element);

  printf("\n");
}

void delet_list(LIST L){

  position tmp, p;
  
  p = L->next;
  L->next = NULL;
  while(p != NULL){
    tmp = p->next;
    free(p);
    p = tmp;
  }

  free(L);  
}

void delet_dup(LIST L){

  position tmp, l, cell, pre;
  
  tmp = L->next;
  while(tmp != NULL){
    l = tmp->next;
    pre = tmp;
    while(l != NULL){
      if(tmp->element == l->element){
         cell = l;
         pre->next = l->next;
         free(cell);
         l = l->next; 
      }
      else{
        l = l->next;
        pre = pre->next;
      }
    }
    tmp = tmp->next;
   
  } 
}






