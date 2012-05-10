#include "singlelink.h"

int compare(LIST L1, LIST L2);

int main(int argc, char *argv[]){

  int i;
  LIST L1 = NULL;
  LIST L2 = NULL;
  int array1[5], array2[6];
  
  for(i=0; i<5; i++)
    array1[i] = 1;

  for(i=0; i<6; i++)
    array2[i] = 1; 

  L1 = init_single_list(array1, 5);
  L2 = init_single_list(array2, 6);

  if(compare(L1, L2))
    printf("l1 == l2\n");
  else
    printf("l1 != l2\n");

  return 0;
}

int compare(LIST L1, LIST L2){

  int result = 0;
  position p1, p2;
  
  p1 = L1;
  p2 = L2;

  if((p1 == NULL)&&(p2 == NULL))
    result = 1;

  if((p1 == NULL)||(p2 == NULL))
    result = 0;
  else{
    if(p1->element != p2->element)
      result = 0;
    else
      compare(p1->next, p2->next);
  }
 return result;   
}
