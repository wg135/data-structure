#include "doublelink.h"

LIST reverse(LIST L);

int main(int argc, char *argv[]){

  int array[10];
  int i;
  LIST L;

  for(i=0; i<10; i++)
    array[i] = i;
  
  L = init_double_list(array, 10);
  L = reverse(L);
  print_double_list(L);

  return 0;
  
}

LIST reverse(LIST L){

  position t, r, y;

  r = NULL;
  y = L;
  
  while(y != NULL){
    r = y->next;
    y->prev = y->next;
    y->next = r;
    y = y->prev;
  }
 
 return L;  
}
