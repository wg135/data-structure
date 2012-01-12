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
TREE_NODE bt_insert(element_type element, BTREE T);
void preorder(BTREE T);
BTREE min_tree(element_type *array, int start, int end, BTREE T);


int main(int argc, char *argv[]){

  element_type array[20];
  int i;
  BTREE T = init_tree();

  for(i=0; i<20; i++){
    array[i] = i + 1;
    printf("%d ", array[i]);
  }
  printf("\n");

  min_tree(array, 0, 19, T);
  preorder(T->right);
  printf("\n");
  
}

BTREE init_tree(){

  BTREE T;

  T =(BTREE)malloc(sizeof(struct btree_node));
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
    if(element < T->element)
      T->left = bt_insert(element, T->left);
    else
    if(element > T->element)
      T->right = bt_insert(element, T->right); 
  
  return T; 
}

void preorder(BTREE T){

  if(T != NULL){
    printf("%d ", T->element);
    preorder(T->left);
    preorder(T->right);
  }
}

BTREE min_tree(element_type *array, int start, int end, BTREE T){

  BTREE p;
  if(end < start)
    return NULL;
  int min = (start + end)/2;
  bt_insert(array[min], T);
  min_tree(array, start, min-1, T);
  min_tree(array, min+1, end, T);

  return T;
}
