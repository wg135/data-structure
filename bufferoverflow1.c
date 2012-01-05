#include <stdio.h>

void why_here(void){

  printf("why u here?\n");
  _exit(0);
}

int main(int argc, char *argv[]){

  int buff[1];
  buff[2] = (int)why_here;
  
  return 0;
}
