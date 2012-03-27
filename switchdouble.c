#include "doublelink.h"

void exchange2(LIST L);

int main(int argc, char *argv[]){

  int i;
  LIST L;
  element_type array[20];

  for(i=0; i<20; i++)
    array[i] = random(200);
  
  L = init_double_list(array, sizeof(array)/sizeof(array[0]));
  print_double_list(L);
  exchange2(L);
  print_double_list(L);

  free_double_list(L);

  return 0;
 }

void exchange2(LIST L){

  position tmp1, tmp2; 
  element_type tmp;

  if((L == NULL)||(L->next == NULL))
    return;
  
  tmp1 = L;
  tmp2 = tmp1->next;

  while(tmp1 != NULL){
    tmp = tmp1->element;
    tmp1->element = tmp2->element;
    tmp2->element = tmp;
  
    tmp1 = tmp2->next;
    if((tmp1 == NULL)||(tmp2 == NULL))
      break;
    tmp2 = tmp1->next;
  } 

}
