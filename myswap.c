#include <stdio.h>
#include <stdlib.h>

void swap_withvar(int *px, int *py);
void swap_withoutvar(int *px, int *py);

int main(int argc, char *argv[]){
  
  int x = 10;
  int y = 20;
  int *px, *py;
 
  px = &x;
  py = &y;

  swap_withvar(px, py);
  printf("px = %d, py = %d\n", *px, *py);

  swap_withoutvar(px, py);
  printf("px = %d, py = %d\n", *px, *py);

  return 0;
}

void swap_withvar(int *px, int *py){

  int tmp;
  
  tmp = *px;
  *px = *py;
  *py = tmp;
}

void swap_withoutvar(int *px, int *py){

  *px += *py;
  *py = *px - *py;
  *px = *px - *py;
}
