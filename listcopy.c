#include "singlelink.h"

LIST list_copy(LIST L);

int main(int argc, char *argv[]){

  LIST L1 = NULL, L2 = NULL;
  int array[10], i;

 for(i=0; i<10; i++)
    array[i] = i+1;
 
  L1 = init_single_list(array, 10); 
  print_single_list(L1);
  L2 = list_copy(L1);
  print_single_list(L2); 
 
  return 0;
}

LIST list_copy(LIST L){

  position p, p2;
  LIST L2 = NULL;
  
  if(L == NULL)
    return NULL;
  
  p = L;
  L2 = new_node(p->element);
  p2 = L2;
  p = p->next;
  while(p != NULL){
    p2->next = new_node(p->element);
    p2 = p2->next;
    p = p->next;
    
  }
 
  return L2; 
  
}
