/* Given a Binary Tree, find the maximum sum path from a leaf to root*/
#include "binarytree.h"

#define len 50

void maxsum(BTREE T, int result, int max[], int index);
int get_max(BTREE T);

int main(int argc, char *argv[]){

  BTREE T = NULL;

  T = new_node(10);
  T->left = new_node(-2);
  T->right = new_node(7);
  T->left->left = new_node(8);
  T->left->right = new_node(-4);
  printf("%d", get_max(T));
  printf("\n");
  
}


void maxsum(BTREE T, int result, int max[], int index){

   if(T == NULL)
    return;
  result+= T->element;
  if((T->left == NULL)&&(T->right == NULL)){
   max[index++] = result; 
  }
  maxsum(T->left, result, max, index);
  maxsum(T->right, result, max, index);
}

int get_max(BTREE T){
  
  int max[len] = {0};
  int index = 0, tmp = 0;
  maxsum(T, 0, max, index);
  
  for(index=0; index<len; index++){
    if(tmp < max[index])
       tmp = max[index];
  }

  return tmp;
  
  
}
