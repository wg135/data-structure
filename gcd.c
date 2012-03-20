#include <stdio.h>
#include <stdlib.h>

int gcd(int x, int y);

int main(int argc, char *argv[]){

  printf("gcd(42, 30) is %d\n", gcd(42, 30));
  return 0;
}

int gcd(int x, int y){

  if(x < y)
    return gcd(y, x);
  if(y == 0)
    return x;
  else
    return gcd (x-y, y);
}
