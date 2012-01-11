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

int main(int argc, char *argv[]){

  element_type array[20];
  int i;
  BTREE T = init_tree();
  
  for(i=0; i<20; i++){
    array[i] = random(200);
    printf("%d ", array[i]);
  }
  printf("\n");

  T = build_tree(array, sizeof(array)/sizeof(array[0]), T);
  preorder_recursive(T);
  printf("\n");

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


















