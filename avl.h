#include <stdio.h>
#include <stdlib.h>

#define random(x) (rand()%x)

typedef struct avl_node *avl_ptr;
typedef int element_type;

struct avl_node{

  element_type element;
  avl_ptr left;
  avl_ptr right;
  int height;
};

typedef avl_ptr AVL_TREE;
typedef avl_ptr TREE_NODE;

AVL_TREE init_avl_tree();
avl_ptr rotate_right(avl_ptr k2);
avl_ptr rotate_left(avl_ptr k2);
avl_ptr rotate_left_right(avl_ptr k2);
avl_ptr rotate_right_left(avl_ptr k2);
AVL_TREE avl_insert(element_type x, AVL_TREE T);
AVL_TREE avl_insert1(element_type x, AVL_TREE T, avl_ptr parent);
AVL_TREE creat_avl_tree(element_type *array, int total, AVL_TREE T);
static int height(avl_ptr p);
static int max(int h1, int h2);
void preorder(AVL_TREE T);
AVL_TREE test_insert(element_type x, AVL_TREE T);




AVL_TREE init_avl_tree(){

  AVL_TREE T = (AVL_TREE)malloc(sizeof(struct avl_node));
  if(T == NULL){
    printf("init avl tree failed\n");
    exit(1);  
  }
  else{
    T->element = 201;
    printf("%d ", T->element);
    T->left = NULL;
    T->right = NULL;
    T->height = 0;
  }
  
  return T;
}

avl_ptr rotate_right(avl_ptr k2){

  avl_ptr k1;
  
  k1 = k2->left;
  k2->left = k1->right;
  k1->right = k2;

  k2->height = max(height(k2->left), height(k2->right))+1;
  k1->height = max(height(k1->left), height(k1->right))+1;

  return k1;
}

avl_ptr rotate_left(avl_ptr k2){

  avl_ptr k1;

  k1 = k2->right;
  k2->right = k1->left;
  k1->left = k2;

  k2->height = max(height(k2->left), height(k2->right))+1;
  k1->height = max(height(k1->right), height(k1->right))+1;
 
  return k1; 
}

avl_ptr rotate_left_right(avl_ptr k2){

  k2->left = rotate_left(k2->left);
  return rotate_right(k2);
}

avl_ptr rotate_right_left(avl_ptr k2){

  k2->right = rotate_right(k2->right);
  return rotate_left(k2);
}

AVL_TREE avl_insert(element_type x, AVL_TREE T){


  if(T == NULL){
     T = (AVL_TREE)malloc(sizeof(struct avl_node));
    if(T == NULL){
      printf("insert malloc failed\n");
      exit(1);
    }
    else{
       T->element = x;
       T->left = NULL;
       T->right = NULL;
       T->height = 0;
    }
  }
  else{
    if(x < T->element){
      T->left = avl_insert(x, T->left);
      if(height(T->left)-height(T->right) == 2){
        if(x < T->left->element){
          T = rotate_right(T);
   printf("%d %d %d\n", T->element, T->left->element, T->right->element);
      }
        else
          T = rotate_left_right(T);
      }
    }
    else{
      T->right = avl_insert(x, T->right);
      if(height(T->right) - height(T->left) == 2){
        if(x > T->right->element)
          T = rotate_left(T);
        else
          T = rotate_right_left(T);
      }
    }
  }
  T->height = max(height(T->left), height(T->right))+1;
  return T;
}

static int height(avl_ptr p){

  if(p == NULL)
    return -1;
  else
    return p->height;
}

static int max(int h1, int h2){

  return(h1 > h2 ? h1:h2);
}

AVL_TREE creat_avl_tree(element_type *array, int total, AVL_TREE T){

  int i;
  AVL_TREE p;
  p = T;
  
  for(i=0; i<2; i++)
    avl_insert(*(array+i), T);

  return T;
}

void preorder(AVL_TREE T){

 if(T != NULL){
    printf("%d ", T->element);
    preorder(T->left);
    preorder(T->right);
 }
}

AVL_TREE test_insert(element_type x, AVL_TREE T){

  if(T == NULL){
    T = (AVL_TREE)malloc(sizeof(struct avl_node));
    T->element = x;
    T->left = NULL;
    T->right = NULL;
   }
   else{
     T->left = test_insert(x, T->left);
   }

  return T;

  
}



