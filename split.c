#include "singlelink.h"

void split_list(LIST L, LIST L1, LIST L2);

int main(int argc, char *argv[]){

  int array[5] = {2, 3, 5, 7, 11};
  LIST L = NULL, L1 = NULL, L2 = NULL;
  int i;
  position p;
  
  L = new_node(0);
  L1 = new_node(0);
  L2 = new_node(0);
 
  p = L;
  for(i=0; i<5; i++){
    p = insert(array[i], p);
  } 
  print_single_list(L->next);
  split_list(L->next, L1, L2);
  print_single_list(L1->next);
  print_single_list(L2->next);
  return 0;
}

void split_list(LIST L, LIST L1, LIST L2){
 
  position p1 = L1, p2 = L2;
  position fast = L, slow = L, p = NULL; 
  if(L == NULL)
    return;

  while(fast != NULL){
    p = slow;
    fast = (fast->next != NULL)? fast->next->next : NULL;
    slow = slow->next;
  }
    p->next = NULL;
    L1->next = L;
    L2->next = slow;
}
