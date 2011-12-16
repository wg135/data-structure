#include "myhash.h"

int main(int argc, char *argv[]){

  HASH_TABLE H;
  position tmp;

  H = init_table(17);
  hash_insert(21, H);
  tmp = hash_find(21, H);

  //printf("hi\n");
  printf("the value is %d\n", tmp->element);
  
  return 0;
}
