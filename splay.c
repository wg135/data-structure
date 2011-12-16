#include "splay.h"

int main(int argc, char *argv[]){

  element_type test_array[20];
  int i;
  SPLAY_TREE T = NULL;
  
  for(i=0; i<20; i++){
    test_array[i] = random(200);
    printf("%d ", test_array[i]);
  }
  printf("\n");
}
