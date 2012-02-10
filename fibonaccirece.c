#include <stdio.h>
#include <stdlib.h>

int recurse(int num);

int main(int argc, char *argv[]){

  printf("f(15) = %d\n", recurse(15));
  return 0;
  
}

int recurse(int num){

  if(num < 0)
    exit(1);
  if(num == 0)
    return 0;
  if(num == 1)
    return 1;
  else
    return(recurse(num-1)+recurse(num-2));
  
}
