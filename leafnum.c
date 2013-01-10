// caluate the number of leaf in one tree

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

TREE_NODE new_node(element_type element);
TREE_NODE bt_insert(element_type element, BTREE T);
void inorder(BTREE T);
void free_tree(BTREE T);
int leaf_num(BTREE T);

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
 
  printf("leaf number is %d\n", leaf_num(T)); 
  free_tree(T);
  return 0;
}

TREE_NODE new_node(element_type element){

  TREE_NODE T = (TREE_NODE)malloc(sizeof(struct btree_node));
  if(T == NULL){
    printf("insert malloc error\n");
    exit(1);
  }
  else{
    T->element = element;
    T->left = NULL;
    T->right = NULL;
  }
  return T;
}

TREE_NODE bt_insert(element_type element, BTREE T){

  TREE_NODE tmp;
  
  if(T == NULL){
    return new_node(element);
  }
  else{
    if(element < T->element){
      tmp = bt_insert(element, T->left);
      T->left = tmp;
    }
    if(element > T->element){
      tmp = bt_insert(element, T->right);
      T->right = tmp;
    }
  return T;
  }
}

void inorder(BTREE T){

  if(T != NULL){
    inorder(T->left);
    printf("%d ", T->element);
    inorder(T->right);
  }
}
void free_tree(BTREE T){

  if(T != NULL){
    free_tree(T->left);
    free_tree(T->right);
    free(T);
  }
}

int leaf_num(BTREE T){

  if(T == NULL)
    return 0;

  if((T->left == NULL)&&(T->right == NULL))
    return 1;
  else
   return (leaf_num(T->left) + leaf_num(T->right));
}

