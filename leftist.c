#include "leftist.h"

int main(int argc, char *argv[]){

  int i;
  PQ p;
  PQ H = (tree_ptr)malloc(sizeof(struct tree_node));
  H->element = 1;
  H->left = H->right = NULL;
  
  p = H;

  for(i=4; i<20; i++)
     p = insert1(i, p);
  if(p == NULL){
   printf("H is empty\n");
   exit(1);
  }
  printf("%d\n", H->element);
  return 0;
}
