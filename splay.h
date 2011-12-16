#include <stdio.h>
#include <stdlib.h>

#define random(x) (rand()%x)
#define Error( Str )        FatalError( Str )
#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )

typedef struct splay_node *splay_ptr;
typedef int element_type;

struct splay_node {

  element_type element;
  splay_ptr left;
  splay_ptr right;
  splay_ptr parent;
};

typedef splay_ptr SPLAY_TREE;
typedef splay_ptr SPLAY_NODE;

SPLAY_TREE splay(SPLAY_NODE x, SPLAY_NODE y);
SPLAY_NODE zig(SPLAY_NODE x);
SPLAY_NODE zag(SPLAY_NODE x);

SPLAY_TREE splay(SPLAY_NODE x, SPLAY_NODE y){

  while(x->parent != y){  
    
  }

  
}

SPLAY_NODE zig(SPLAY_NODE x){

  SPLAY_NODE y;
  
  y = x->parent;
  y->left = x->right;

  if(x->right != NULL)
    x->right->parent = y;

  x->parent = y->parent;
  if(y->parent != NULL){
    if(y == y->parent->left)
      y->parent->left = x;
    else
      y->parent->right = x;
  }
  
  x->right = y;
  y->parent = x;
  
  return x;
}

SPLAY_NODE zag(SPLAY_NODE x){

  SPLAY_NODE y;

  y = x->parent;
  y->right = x->left;

  if(x->left != NULL)
    x->left->parent = y;
  
  x->parent = y->parent;
  if(y->parent != NULL){
    if(y == y->parent->left)
      y->parent->left = x;
    else
      y->parent->right = x;
  } 

  x->left = y;
  y->parent = x;

  return x;  
}











