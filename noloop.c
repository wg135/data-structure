#include <stdio.h>
#include <stdlib.h>

void foo(int num);

int main(int argc, char *argv[]){

  foo(10);
  printf("\n");
  return 0;
}

void foo(int num){

  if(num < 0)
    return;
  else{
    foo(num-1);
    printf("%d ", num);
  }
}
