#include "singlelink.h"

int detect(LIST L);

int main(int argc, char *argv[]){
  
  int i;
  LIST L = new_node(0);
  position p = L, tmp = NULL;
 
  for(i=1; i<=6; i++){
    p = insert(i, p);
  }
  tmp = L->next->next;
  p->next = tmp;
 
  if(detect(L))
    printf("has loop\n"); 
  else
    printf("has not loop\n");

  return 0;
}

int detect(LIST L){

  position fast, slow;
  
  fast = L, slow = L;
  while(fast && slow && fast->next){
    fast = fast->next->next;
    slow = slow->next;
    
   if(fast == slow)
     return 1;
  }
  
  return 0;
}
