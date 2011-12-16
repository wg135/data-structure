#include "myheap.h"

int main(int argc, char *argv[]){

  element_type result;

  PRIORITY_QUEUE H = creat_pq(20);
  heap_insert(14, H);
  heap_insert(13, H);
  heap_insert(16, H);
  heap_insert(21, H);
  heap_insert(32, H);
  
  result = delete_min(H); 
  printf("%d\n", result); 
 
  free(H);
  return 0;
}
