#include "btree.h"

int main(int argc, char *argv[]){

  element_type test_array[20];
  int i;
  BTREE T = init_tree();
  TREE_NODE p;
  int height;
 
  
  for(i=0; i<20; i++){
    test_array[i]= random(200);
    printf("%d, ", test_array[i]);
  }
  printf("\n");
  T =  creat_tree(test_array, sizeof(test_array)/sizeof(test_array[0]), T);
  height = height_recursive(T);
  printf("height is %d\n", height);

  printf("preorder:\n");
  preorder_recursive(T); 
  printf("\n");

  printf("inoder:\n");
  inorder_recursive(T);
  printf("\n");

  printf("postorder:\n");
  postorder_recursive(T);
  printf("\n");

  printf("preorder nonrec:\n");
  preorder_norecursive(T);
  printf("\n");

  printf("inorder nonrec:\n");
  inorder_norecursive(T);
  printf("\n");

  printf("postorder nonrec:\n");
  postorder_norcursive(T);
  printf("\n");
 
  printf("levelorder:\n");
  levelorder(T);
  printf("\n");

  printf("print leaf recursive:\n");
  output_leaf_recursive(T);
  printf("\n"); 

  printf("print leaf norecursive\n");
  output_leaf_norecursive(T);
  printf("\n");

  printf("find an element\n");
  if(find_tree(177, T) == NULL)
    printf("no such element\n");
  else
    preorder_recursive(find_tree(177, T));
  printf("\n");

  printf("min node\n");
  visit(find_min(T)->element);
  printf("\n");
  
  printf("max node\n");
  visit(find_max(T)->element);
  printf("\n");

  printf("delet:\n");
  tree_delete(115, T);
  preorder_recursive(T);
  printf("\n");
  
  printf("exchange tree:\n");
  exchange_recursive(T);
  preorder_recursive(T);
  printf("\n");

  printf("exchange tree norecursive:\n");
  exchange_norecursive(T);
  preorder_recursive(T);
  printf("\n");


  free_tree(T);
 
  return 0;
}
