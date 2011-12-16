#include <stdio.h>
#include <stdlib.h>
#include "linked.h"

int main(int argc, char *argv[]){

  int p[10], l[10];
  int i;
  postion tmp_p, tmp_l, start, r_p, r_l;
  LIST P, L;
  
  for(i=0; i<10; i++){
    p[i] = 2*(i+1);
    l[i] = 2*i+1; 
  }

  L = init_list();
  P = init_list();
  r_p = P;
  r_l = L;
  
  for(i=0; i<10; i++){
    tmp_p = (postion)malloc(sizeof(struct node));
    tmp_l = (postion)malloc(sizeof(struct node));
    if((tmp_p == NULL) ||(tmp_l == NULL)){
      printf("malloc unit failed\n");
      exit(1);
    } 
    
    tmp_p->element = p[i];
    tmp_l->element = l[i];
    tmp_p->next = NULL;
    tmp_l->next = NULL;
    r_p->next = tmp_p;
    r_l->next = tmp_l;
    r_p = r_p->next;
    r_l = r_l->next; 
  }

  for(start = P->next; start != NULL; start = start->next)
    printf("%d\t", start->element);
  printf("\n");
  
  for(start = L->next; start != NULL; start = start->next)
    printf("%d\t", start->element);
  printf("\n");
  
 P =  union_list(P, L);
  for(start = P->next; start != NULL; start = start->next)
    printf("%d\t", start->element);
  printf("\n");


 
}
