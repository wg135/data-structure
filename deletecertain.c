#include "singlelink.h"

void delete(LIST L, position t);

int main(int argc, char *argv[]){

  int array[10];
  int i;
  position tmp;
  LIST L = NULL;

  for(i=0; i<10; i++)
    array[i] = i;
   
  L = init_single_list(array, 10);
  tmp = L;
  for(i=0; i<5; i++)
  tmp = tmp->next;
    
  delete(L, tmp);
  print_single_list(L); 
  return 0;
}

void delete(LIST L, position t){

  position p;

  if(t->next != NULL){
    t->element = t->next->element;
    p = t->next;
    t->next = t->next->next;
    free(p);
  }
  if(t->next == NULL){
    free(t);
  }
}

