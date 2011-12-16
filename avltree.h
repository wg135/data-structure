#include <stdio.h>
#include <stdlib.h>

#define random(x) (rand()%x)

typedef struct avl_node *avl_ptr;
typedef int element_type;

struct avl_node {

  element_type element;
  avl_ptr left;
  avl_ptr right;
  int height;
};

typedef avl_ptr AVL_TREE;
typedef avl_ptr AVL_NODE;

static int Max(int h1, int h2);
static int Height(AVL_NODE T);
AVL_NODE rotate_right(AVL_NODE k2);
AVL_NODE rotate_left(AVL_NODE k2);
AVL_NODE rotate_left_right(AVL_NODE k2);
AVL_NODE rotate_right_left(AVL_NODE k2);
AVL_NODE avl_insert(element_type x, AVL_TREE T);
AVL_TREE creat_avl_tree(element_type *array, int total, AVL_TREE T);
void preorder(AVL_TREE T);
AVL_TREE init_avl_tree();
AVL_TREE avl_delete(element_type x, AVL_TREE T);
AVL_NODE rotate(AVL_TREE T);

static int Max(int h1, int h2){

  return(h1 > h2? h1: h2); 
}

static int Height(AVL_NODE T){

  if(T == NULL)
    return -1;
  else
    return T->height;
}

AVL_NODE rotate_left(AVL_NODE k2){

  AVL_NODE k1;
  
  k1 = k2->right;
  k2->right = k1->left;
  k1->left = k2;
  
  k2->height = Max(Height(k2->left), Height(k2->right)) + 1;
  k1->height = Max(Height(k1->left), Height(k1->right)) + 1;
  
  return k1;  
}

AVL_NODE rotate_right(AVL_NODE k2){

  AVL_NODE k1;
  
  k1 = k2->left;
  k2->left = k1->right;
  k1->right = k2;

  k2->height = Max(Height(k2->left), Height(k2->right)) + 1;
  k1->height = Max(Height(k1->left), Height(k1->right)) + 1;

  return k1;
}

AVL_NODE rotate_left_right(AVL_NODE k2){

  k2->left = rotate_left(k2->left);
  return rotate_right(k2);
}

AVL_NODE rotate_right_left(AVL_NODE k2){

  k2->right = rotate_right(k2->right);
  return rotate_left(k2);
}

AVL_NODE avl_insert(element_type x, AVL_TREE T){

  if(T == NULL){
    T = (AVL_TREE)malloc(sizeof(struct avl_node));
    if(T == NULL){
     printf("malloc failed\n"); 
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
      if(Height(T->left) - Height(T->right) == 2){
        if(x < T->left->element)
          T = rotate_right(T);
        else
          T = rotate_left_right(T);
      }
    }
    else
    if(x > T->element){
      T->right = avl_insert(x, T->right);
      if(Height(T->right) - Height(T->left) == 2){
	if(x > T->right->element)
          T = rotate_left(T);
        else
	  T = rotate_right_left(T);
      }
    }
  }

  T->height = Max(Height(T->left), Height(T->right)) + 1;
  return T; 
}

AVL_TREE creat_avl_tree(element_type *array, int total, AVL_TREE T){

  int i;
  AVL_NODE p;
  p = T;

  for(i=0; i<total; i++)
    p = avl_insert(*(array+i), p);
  
  return p;
}

void preorder(AVL_TREE T){

  if(T != NULL){
    printf("%d ", T->element);
    preorder(T->left);
    preorder(T->right);
  }
}

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

AVL_TREE avl_delete(element_type x, AVL_TREE T){

  if(T == NULL)
    return NULL;
  if(T->element = x){
    if(T->right == NULL){
      AVL_NODE tmp = T;
      T = T->left;      
      free(T);
    }
    else{
      AVL_NODE head = T->right;
      while(head->left){
        head = head->left;
      }
      T->element = head->element;
      T->right = avl_delete(T->element, T->right);
      T->height = Max(Height(T->left), Height(T->right)) + 1;
    }
    return T;
  }
  else 
  if(T->element < x){
    avl_delete(x, T->right);
    if(T->right)
      rotate(T->right);
  }
  else
  if(T->element > x){
    avl_delete(x, T->left);
    if(T->left)
      rotate(T->left);
  }
  if(T)
    rotate(T);
}

AVL_NODE rotate(AVL_TREE T){

  if(Height(T->left) - Height(T->right) == 2){
    if(Height(T->left->left) >= Height(T->left->right))
      T = rotate_left(T);
    else
      T = rotate_left_right(T);
  }
  if(Height(T->right) - Height(T->left) == 2){
    if(Height(T->right->right) >= Height(T->right->left))
      T = rotate_right(T);
    else
      T = rotate_right_left(T);
  }

  return T;
}

