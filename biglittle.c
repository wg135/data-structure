// Code to find endianness of a machine.
#include <stdio.h>

#define LITTLE 0
#define BIG 1

int test(){

  int tester = 0x0100;
  char *byte = (char *)&tester;
  return (byte[0]? BIG: LITTLE);
}

int main(int argc, char *argv[]){

  if(test())
    printf("system is big-end\n");
  else
    printf("system is little-end\n");

  return 0;
}
