#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node *tree_ptr;
typedef int element_type;

struct tree_node{

  element_type element;
  tree_ptr left;
  tree_ptr right;
  unsigned int npl;  
};

typedef tree_ptr PQ;

#define insert(x, H) (H = insert1((x), H))

PQ merge(PQ H1, PQ H2);
PQ merge1(PQ H1, PQ H2);
void swap_child(PQ H);
PQ insert1(element_type x, PQ H);
PQ delete_min1(PQ H);

PQ merge(PQ H1, PQ H2){

  if(H1 == NULL)
    return H2;
  if(H2 == NULL)
    return H1;

  if(H1->element > H2->element)
    return merge1(H1, H2);
  else
    return merge1(H2, H1);
}

PQ merge1(PQ H1, PQ H2){

 if(H1->left == NULL)
    H1->left = H2;
  else{
    H1->right = merge(H1->right, H2);
    if(H1->left->npl < H1->right->npl)
      swap_child(H1);

    H1->npl = H1->right->npl + 1;
  } 
  return H1;
}

void swap_child(PQ H){
  
  PQ tmp;
  tmp = H->left;
  H->left = H->right;
  H->right = tmp;
}

PQ insert1(element_type x, PQ H){

  tree_ptr single_node;
  
  single_node = (tree_ptr)malloc(sizeof(struct tree_node));
  if(single_node == NULL){
    printf("single node malloc failed\n");
    exit(1);
  }
  else{
    single_node->element = x;
    single_node->left = single_node->right = NULL;
    H = merge(single_node, H);  
  }
  return H;
}

PQ delete_min1(PQ H){

  PQ left_heap, right_heap;
  
  left_heap = H->left;
  right_heap = H->right;
  free(H);
  return merge(left_heap, right_heap);
}




