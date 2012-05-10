#include "singlelink.h"

position middle(LIST L);

int main(int argc, char *argv[]){

  int i;
  LIST L = NULL;
  int array[10];
  
  for(i=0; i<10; i++)
    array[i] = i;

  L = init_single_list(array, 10);
  
  print_single_list(L);

  printf("%d\n", middle(L)->element);

  return 0;
}

position middle(LIST L){

  position p1, p2;
  
  if(L == NULL)
   return NULL;

  p1 = L; //init pointers
  p2 = L;
  
  while(p1->next->next != NULL){
    p1 = p1->next->next;
    p2 = p2->next;
  } 
  
  return p2;
}
