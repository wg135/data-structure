/* find the k large element in binary tree*/
/* use reverse in order travel to find out*/

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
element_type klarge(BTREE T, int k);

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

  printf("the 5th largest element is %d\n", klarge(T, 5));
  free_tree(T);
  return 0;
}

element_type klarge(BTREE T, int k){

  static int k2 = 1;
  static int data = -1;

  BTREE tmp = T;

  if(k < 0){
    printf("k less 0");
    exit(1);
  }
  if(T == NULL)
    return -1;

    klarge(tmp->right, k);
    if(k2 == k)
      data = T->element;
    k2++;
    klarge(T->left, k);

  return data;
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

  TREE_NODE tmp;
  tmp = T;

  if(tmp != NULL){
    inorder(tmp->left);
    printf("%d ", tmp->element);
    inorder(tmp->right);
  }
}

void free_tree(BTREE T){

  if(T != NULL){
    free_tree(T->left);
    free_tree(T->right);
    free(T);
  }
}
