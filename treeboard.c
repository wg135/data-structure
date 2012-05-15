/* print the the boad of the binary search tree*/

#include "binarytree.h"

void print_board(BTREE T);
void print_leaf(BTREE T);

int main(int argc, char *argv[]){

  element_type array[20];
  int i;
  BTREE T = NULL;

  for(i=0; i<20; i++){
    array[i] = random(200);
    printf("%d ", array[i]);
    T = bt_insert(array[i], T);
  }
  printf("\n");
  inorder(T);
  printf("\n");
  print_board(T);
  printf("\n");
  free_tree(T);
  return 0;
}

void print_board(BTREE T){

  TREE_NODE p;
 
  if(T == NULL)
    return;

  p = T;
  while(p->left != NULL){ // left board
    p = p->left;
    printf("%d ", p->element);
  } 

 p = T; //leaf board
  print_leaf(p);
 
  p = T;    //right board
  while(p != NULL){
    printf("%d ", p->element);
    p = p->right;
  }

}

void print_leaf(BTREE T){

  if(T == NULL)
    return;
 
  if(T != NULL){
    if((T->left == NULL)&&(T->right == NULL))
      printf("%d ", T->element);
    print_leaf(T->left);
    print_leaf(T->right);
  }  
}







