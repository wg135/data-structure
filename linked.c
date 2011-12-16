#include <stdio.h>
#include <stdlib.h>
#include "linked.h"

int main(int argc, char *argv[]){

  int test[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int number = 10;
  int i;
  LIST L, l_re;
  postion final, p, r, insert_p; 
  int empty;
  int magic = 16;
   
  L = init_list();
  /* init the linked list */  
  r = L;
  for(i=0; i<10; i++)
    {
      p = (postion)malloc(sizeof(struct node));
      if(p == NULL){
        printf("mallco unit failed\n");
        exit(1);
      }
      p->element = test[i];
      p->next = NULL; 
      r->next = p;
      r = r->next; 
     }
  for(final = L->next; final != NULL; final = final->next)
    printf("%d\t",final->element);
  printf("\n");

  empty = is_empty(L);
  if(empty)
    printf("L is an empty list\n");
  else
    printf("L is not an empty list\n");  
  
 // insert_p = (postion)malloc(sizeof(struct node));
 // insert_p = L->next->next->next;
 // insert(magic, L, 3);
  l_re = reversal_list(L);
  
  for(final = l_re; final != NULL; final = final->next)
    printf("%d\t", final->element);
   printf("\n");
    
//  my_delete(16, L);
  /*for(final = L->next; final != NULL; final = final->next)                   
    printf("%d\t", final->element); 
   printf("\n");    */
}
