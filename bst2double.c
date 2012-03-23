/* covert a binary search tree to double linked list*/
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
void treefree(BTREE T);
TREE_NODE covert_solution(BTREE T);
void convertdouble(TREE_NODE T, TREE_NODE lastnodelist);

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

  treefree(T);
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

void treefree(BTREE T){

  if(T != NULL){
    treefree(T->left);
    treefree(T->right);
    free(T);
  }
}

TREE_NODE covert_solution(BTREE T){
  
  TREE_NODE headlist;
  TREE_NODE lastnodelist = NULL;

  convertdouble(T, lastnodelist);
  headlist = lastnodelist;
  
  while(headlist && headlist->left)
    headlist = headlist->left;

  return headlist;
}

void convertdouble(TREE_NODE T,TREE_NODE lastnodelist){

  TREE_NODE tmp;

  if(T == NULL)
    return;

  tmp = T;
  if(tmp->left != NULL)
    convertdouble(tmp->left, lastnodelist);
  
  tmp->left = lastnodelist;
  if(lastnodelist != NULL)
    lastnodelist->right = tmp;

  lastnodelist = tmp;
 
  if(tmp->right != NULL)
    convertdouble(tmp->right, lastnodelist);
}



