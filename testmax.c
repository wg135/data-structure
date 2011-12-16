#include <stdio.h>

int main(int argc, char *argv[]){

  int a = 30, b = 20;
  
  printf("max is %d\n", max(a, b));
 
  return 0;
}

int max(int a, int b){

  return (a>b? a:b);
}
