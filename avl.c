#include "avl.h"

int main(int argc, char *argv[]){

  element_type test_array[20];
  int i;
  AVL_TREE T = init_avl_tree();

  for(i=0; i<20; i++){
    test_array[i] = random(200);
    printf("%d ", test_array[i]);
  }
  printf("\n");

  
  T = creat_avl_tree(test_array, sizeof(test_array)/sizeof(test_array[0]), T);

  printf("preorder print the AVL tree:\n");
  preorder(T);
  printf("\n");



  return 0;


}
