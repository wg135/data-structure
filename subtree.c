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
BTREE creat_tree(element_type *array, int total, BTREE T);
TREE_NODE bt_insert(element_type element, BTREE T);
void preorder(BTREE T);
void free_tree(BTREE T);
int contain_tree(BTREE T1, BTREE T2);
int sub_tree(BTREE T1, BTREE T2);
int match_tree(TREE_NODE T1, TREE_NODE T2);

int main(int argc, char *argv[]){

  element_type array[20];
  element_type array1[20];
  int i;  
  BTREE T1 = init_tree();
  BTREE T2 = init_tree();
  BTREE T3 = NULL;

  for(i=0; i<20; i++){
    array[i] = random(200);
    array1[i] = i;
    printf("%d ", array[i]);
  }
  printf("\n");

  T1 = creat_tree(array, sizeof(array)/sizeof(array[0]), T1);
  T2 = creat_tree(array, 1, T2);

  preorder(T1);
  printf("\n");
  preorder(T2);
  printf("\n");

  if(contain_tree(T1, T2))
    printf("T1 contains T2\n");
  else
    printf("T1 doesn't contain T2\n");

  free_tree(T1);
  free_tree(T2);

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

BTREE creat_tree(element_type *array, int total, BTREE T){

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

void preorder(BTREE T){

  BTREE p;

  p = T;

  if(p != NULL){
    printf("%d ", p->element);
    preorder(p->left);
    preorder(p->right);
  }
}

void free_tree(BTREE T){

  if(T != NULL){
    free_tree(T->left);
    free(T);
    free_tree(T->right);
  }
}

int contain_tree(BTREE T1, BTREE T2){

  if(T2 == NULL)
    return 1;
  else
    return sub_tree(T1, T2);
}

int sub_tree(BTREE T1, BTREE T2){

  if(T1 == NULL){
    printf("shit\n");
    return 0;
  }
  if(T1->element == T2->element){
    if(match_tree(T1, T2)) 
      return 1;
  }
   
  return (sub_tree(T1->left, T2) ||sub_tree(T1->right, T2));
}

int match_tree(TREE_NODE T1, TREE_NODE T2){

  if((T1 == NULL)&&(T2 == NULL))
    return 1;
  if((T1 == NULL)||(T2 == NULL))
    return 0;
  if(T1->element != T2->element)
    return 0;

  return (match_tree(T1->left, T2->left) && match_tree(T1->right, T2->right));
}

