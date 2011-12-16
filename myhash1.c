#include "myhash1.h"

int main(int argc, char *argv[]){

  HASH_TABLE H, H1;
  position tmp;

  H = init_table(17);
  insert(21, H);
  insert(38, H);
  //insert(54, H);
  tmp = find(38, H);

  printf("the position is %d\n", tmp);
  
  return 0;
}
