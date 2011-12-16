#include <stdio.h>
#define random(x) rand()%x

void printlen(int *array){

  printf("len in array = %d\n", sizeof(array));
}

int main(int argc, char *argv[]){

  int i;
  int array[20];
  int len;
 
  for(i=0; i<20; i++)
    array[i] = random(100);

  len = sizeof(array)/sizeof(array[0]);
  
  printf("len = %d\n", len);

  printlen(array);

  
  return 0;
  
  
}
