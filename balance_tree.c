#include <stdio.h>
#include <stdlib.h>

#define random(x) (rand()%x)

typedef struct btree_node *btree_ptr;
typedef int element_type;

struct btree_node{

  element_type element;
  btree_ptr left;
  btree_ptr right;
};

typedef btree_ptr BTREE;
typedef btree_ptr TREE_NODE;


BTREE init_tree();
BTREE build_tree(element_type *array, int total, BTREE T);
TREE_NODE bt_insert(element_type element, BTREE T);
void preorder_recursive(BTREE T);
int check_balance(BTREE T);
int min_height(BTREE T);
int max_height(BTREE T);

int main(int argc, char *argv[]){

  element_type array[3];
  int i;
  BTREE T = init_tree();
  
  for(i=0; i<3; i++){
    array[i] = i+1;
    printf("%d ", array[i]);
  }
  printf("\n");

  T = build_tree(array, sizeof(array)/sizeof(array[0]), T);
  preorder_recursive(T);
  printf("\n");
  
  if(check_balance(T))
    printf("it is balance\n");
  else
    printf("not balance\n");

  return 0;

}

BTREE init_tree(){

  BTREE T = (TREE_NODE)malloc(sizeof(struct btree_node));
  if(T == NULL){
    printf("init malloc error\n");
    exit(1);
  }
  else{
    T->left = NULL;
    T->right = NULL;
  }

  return T;
}

BTREE build_tree(element_type *array, int total, BTREE T){

  int i;
  BTREE p;
  T->element = *array;
  p = T;
 

  for(i=1; i<total; i++)
    bt_insert(*(array+i), p);


  return T;
}

TREE_NODE bt_insert(element_type element, BTREE T){

  if(T == NULL){
    T = (TREE_NODE)malloc(sizeof(struct btree_node));
    if(T == NULL){
      printf("insert malloc error\n");
      exit(1);
    }
    else{
      T->element = element;
      T->left = NULL;
      T->right = NULL;
    }
  }
  else
  if(element < T->element){
    T->left = bt_insert(element, T->left);
  }
  else
  if(element > T->element){
    T->right = bt_insert(element, T->right);
  }
  
  return T; 
}

void preorder_recursive(BTREE T){

  if(T != NULL){
    printf("%d ", T->element);
    preorder_recursive(T->left);
    preorder_recursive(T->right);
  }

}

int check_balance(BTREE T){

  int minheight = 0, maxheight = 0;
  int height;
  
  if(T == NULL)
    return -1;

  minheight = min_height(T);
  maxheight = max_height(T);
  
  return ((maxheight - minheight) < 1); 
}

int min_height( BTREE T){

  int height_l, height_r;

  if(T == NULL)
    return 0;

  height_l = min_height(T->left);
  height_r = min_height(T->right);
  if(height_l < height_r)
    return height_l + 1;
  else
    return height_r + 1;
  
}

int max_height(BTREE T){

  int height_l, height_r;

  if(T == NULL)
    return 0;

  height_l = max_height(T->left);
  height_r = max_height(T->right);
  if(height_l > height_r)
    return height_l + 1;
  else
    return height_r + 1;

}
















