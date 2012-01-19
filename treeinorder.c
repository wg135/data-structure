#include <stdio.h>
#include <stdlib.h>

#define random(x) (rand()%x)

typedef struct btree_node *btree_ptr;
typedef int element_type;

struct btree_node{

  element_type element;
  btree_ptr parent;
  btree_ptr left;
  btree_ptr right;
};

typedef btree_ptr BTREE;
typedef btree_ptr TREE_NODE;

TREE_NODE new_node(element_type element);
TREE_NODE bt_insert(element_type element, BTREE T);
void inorder(BTREE T);
void free_tree(BTREE T);
TREE_NODE tree_insucc(TREE_NODE p);
TREE_NODE find_min(BTREE T);

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

  if(tree_insucc(T) != NULL)
  printf("%d\n", (tree_insucc(T)->element));

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
    T->parent = NULL; 
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
      tmp->parent = T;
    }
  if(element > T->element){
     tmp = bt_insert(element, T->right);
     T->right = tmp;
     tmp->parent = T;
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

TREE_NODE tree_insucc(TREE_NODE p){

  TREE_NODE tmp;

  if(p != NULL){
    if(p->right != NULL)
      return find_min(p->right);
    else{
      tmp = p->parent;
      if(tmp != NULL){
        if(tmp->left == p)
          return tmp;
        if(tmp->right == p)
          return tree_insucc(tmp);
      }
    }
  }
  else
    return NULL;
}

TREE_NODE find_min(BTREE T){
 
  TREE_NODE tmp;
  
  tmp = T;
  if(tmp != NULL){
    tmp = tmp->left;
  }

  return tmp;
}
