#include <stdio.h>
#include <stdlib.h>

#define random(x) (rand()%x)
#define K 5

typedef struct node *node_ptr;
typedef int element_type;

struct node{

  element_type element;
  node_ptr next;
};

typedef node_ptr LIST;
typedef node_ptr position;

position init_list();
void insert_list(element_type element, LIST L);
void print_list(LIST L);
void delet_list(LIST L);
position kth_list(LIST L);
position kth2_list(LIST L);

int main(int argc, char *argv[]){

  LIST L;
  int i;
  position tmp;

  L = init_list();
  for(i=0; i<20; i++)
    insert_list(random(200), L);

  print_list(L);
  tmp = kth_list(L);
  printf("5th to last is %d\n", tmp->element);
  tmp = kth2_list(L);
  printf("5th to last is %d\n", tmp->element);
  delet_list(L);

  return 0;
}

position init_list(){

  LIST L;
  
  L = (position)malloc(sizeof(struct node));
  if(L == NULL){
    printf(" init list malloc error\n");
    exit(1);
  }
  L->next = NULL;
  
  return L;
}

void insert_list(element_type element, LIST L){

  position tmp;

  tmp = (position)malloc(sizeof(struct node));
  if(tmp == NULL){
    printf("insert malloc error\n");
    exit(1);
  }
  else{
    tmp->element = element;
    tmp->next = L->next;
    L->next = tmp;
  }
  
}

void print_list(LIST L){

  position l;
  
  l = L->next;
  while(l != NULL){
    printf("%d ", l->element);
    l = l->next;
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

position kth_list(LIST L){

  int cnt = 0;
  int i;
  position tmp, l;
  
  l = L->next;
  tmp = L->next;
  while(l != NULL){
    l = l->next;
    cnt++;
  }

  for(i=0; i<cnt-K; i++)
    tmp = tmp->next;
   
  return tmp;    
}

position kth2_list(LIST L){

  position tmp1, tmp2;
  int i = 0;

  tmp1 = L->next;
  tmp2 = L->next;

  while(tmp1 != NULL){
    tmp1 = tmp1->next;
    i++;
    if(i > K)
      tmp2 = tmp2->next;    
  } 
 
  return tmp2;
}








