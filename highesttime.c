#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]){

  time_t high = 0x7fffffff;
  
  printf("%s\n", ctime(&high));

  return 0;
}
