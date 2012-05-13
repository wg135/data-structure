#include "singlelink.h"

void swapk(LIST L, int k);

int main(int argc, char *argv[]){

  int array[10];
  int i;
  LIST L = NULL;

  for(i=0; i<10; i++)
    array[i] = i+1;

  L =init_single_list(array, 10);
  swapk(L, 3); 
  print_single_list(L);

  return 0;
}

void swapk(LIST L, int k){

  position p;
  int list_len = 0;
  position p1, p2, tmp1;
  int i = 0, j;
  int tmp;
   

  if(k <= 0)
    return;

  if(L == NULL)
    return;

  //get the length linked list 
  p = L;
  while(p != NULL){
    ++list_len;
    p = p->next;
  }
  if(k > list_len){
    printf("LIST IS OF LESSER SIZE\n");
    exit(1);
  } 
  
  p1 = L;
  p2 = L;

  for(i=1; i<k; i++)
    p1 = p1->next; 

  for(j=1; j<(list_len -k+1); j++)
    p2 = p2->next;
  
    tmp = p1->element;
    p1->element = p2->element;
    p2->element = tmp; 

}
