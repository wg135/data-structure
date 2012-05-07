#include "singlelink.h"

LIST reverse(LIST L);

int main(int argc, char *argv[]){

  LIST L = NULL;
  int array[10];
  int i;

  for(i=0; i<10; i++)
    array[i] = i;

  L = init_single_list(array, 10);
  L = reverse(L);
  
  print_single_list(L);

  return 0;

}

LIST reverse(LIST L){
 
  position t, y, r;

  y = L;
  r = NULL;
  while(y != NULL){
   t = y->next;
   y->next = r;
   r = y;
   y = t; 
  }
  return r;
} 
