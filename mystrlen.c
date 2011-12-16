#include <stdio.h>
#include <stdlib.h>

int string_len(const char *str);

int main(int argc, char *argv[]){

  int i;
  if(argc != 2){
    printf("usage: ./a.out ""string");
    exit(1);
  }

  i = string_len(argv[1]);
  printf("string length is %d\n", i);
  return 0;
}

int string_len(const char *str){
  
  int i = 0;
  while(*str++ != '\0'){
    i++;
  }
  return i;
}
