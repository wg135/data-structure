#include <stdio.h>
#include <stdlib.h>
#include "polynomial.h"

int main(int argc, char argv[]){

  LIST poly1, poly2, final;
  int i; 
  position tmp_poly1, tmp_poly2, start, p1, p2;

  poly1 = init_list();
  poly2 = init_list();
  final = init_list();
  p1 = poly1;
  p2 = poly2; 
  for(i=0; i<4; i++){
   tmp_poly1 = (position)malloc(sizeof(struct node));
   tmp_poly2 = (position)malloc(sizeof(struct node));
   if((tmp_poly1 == NULL)||(tmp_poly2 == NULL)){
     printf("malloc unit failed\n");
     exit(1);
   }
   tmp_poly1->coefficient = i+1;
   tmp_poly1->exponent = (i+1)*4;
   tmp_poly1->next = NULL;
   p1->next = tmp_poly1;
   p1 = p1->next;
  
   tmp_poly2->coefficient = i+1;
   tmp_poly2->exponent = (i+1)*8;
   tmp_poly2->next = NULL;
   p2->next = tmp_poly2;
   p2 = p2->next;  
  }

  for(start=poly1->next; start != NULL; start = start->next){
    printf("%d*10^%d   ", start->coefficient, start->exponent);
  }
  printf("\n");

  for(start=poly2->next; start != NULL; start = start->next){
    printf("%d*10^%d   ", start->coefficient, start->exponent);
  }
  printf("\n");
  //final = poly_add(final, poly1, poly2);
  final = poly_mulx1(final, poly1, poly2);
  for(start=final->next; start != NULL; start= start->next){
    printf("%d*10^%d   ", start->coefficient, start->exponent);
}

  printf("\n");

return 0;
}
