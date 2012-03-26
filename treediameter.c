/* find out the diameter of a binary tree*/

#include "binarytree.h"

int diameter(BTREE T);
int max(int a, int b);
int height(BTREE T);

int main(int argc, char *argv[]){

  element_type array[20];
  int i;
  BTREE T = NULL;

  for(i=0; i<20; i++){
    array[i] = random(200);
    T = bt_insert(array[i], T);
  }
    inorder(T);
    printf("\n");
    printf("diameter is %d\n", diameter(T));
    free_tree(T);

    return 0;
}

int diameter(BTREE T){

  int height_L = 0 , height_R = 0; //left subtree height and right subtree height
  int diameter_L = 0, diameter_R = 0; //left subtree diameter and right subtree diameter
 
  if(T == NULL)
    return 0;
 
  height_L = height(T->left);
  height_R = height(T->right);

  diameter_L = diameter(T->left);
  diameter_R = diameter(T->right);
  
  return max((height_L + height_R + 1), max(diameter_L, diameter_R));
}

int max(int a, int b){

  return (a>=b? a:b);
}

int height(BTREE T){

  int height_l, height_r;

  if(T ==NULL)
    return 0;
  height_l = height(T->left);
  height_r = height(T->right);
  if(height_l > height_r)
    return height_l + 1;
  else
    return height_r + 1;
}
