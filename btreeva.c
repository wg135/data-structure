#include "binarytree.h"

int fillvalue(TREE_NODE T);

int main(int argc, char *argv[]){

  BTREE T = new_node(0);
  T->left = new_node(0);
  T->right = new_node(0);
  T->left->left = new_node(0);
  T->left->right = new_node(0);
  T->right->right = new_node(0); 
  inorder(T);
  printf("\n");
  fillvalue(T);
  inorder(T);
  printf("\n");
  return 0;
}

int fillvalue(TREE_NODE T){

  TREE_NODE p = T;
  int left, right;

  if(p == NULL)
    return 0;

  left = fillvalue(p->left);
  right = fillvalue(p->right);
  p->element = left - right;
  
  return 1+ left + right;
}
