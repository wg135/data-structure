#include <stdio.h>
#include <stdlib.h>

typedef struct node *node_ptr;
typedef int elementype;

struct node{
  
  node_ptr prev;
  elementype element;
  node_ptr next;
};

typedef node_ptr LIST;
typedef node_ptr position;

LIST init_list();
LIST exchange_two(LIST L);

int main(int argc, char *argv[]){

  int test[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int number = 10;
  int i;
  LIST L;
  position start, l, p;

  L = init_list();
  l = L;

  for(i=0; i<10; i++){
    p = (position)malloc(sizeof(struct node));
    if(p == NULL){
      printf("malloc unit failed\n");
      exit(1);
    } 
   p->element = test[i];
   p->prev = l;
   p->next = NULL;
   l->next = p;
   l = l->next;    
  }

 // L = exchange_two(L);

for(start = L->next; start != NULL; start = start->next)
   printf("%d\t", start->element);

  printf("\n");


}

LIST init_list(){

  LIST p = (position)malloc(sizeof(struct node));
  if(p == NULL){
    printf("init failed\n");
    exit(1);
  }
  p->prev = NULL;
  p->next = NULL;

  return p;  
}

LIST exchange_two(LIST L){

  position p, q, l, r;
  l = L;
  p = l->next;
  q = p->next;

  while((q != NULL)){

    
    

   
  }
  
 
  return L; 

}

