#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strncpy(char *dest, const char *src, int n);

int main(int argc, char *argv[]){

  int n = 5;
  char *a = "aaaaaaaaaa";
  char *b = (char *)malloc( n * sizeof(char));

  if(b == NULL){
   printf("out of space\n");
   exit(1);
  }
 
  my_strncpy(b, a, n);
  
  printf("%s\n", b);
  free(b);
  
  return 0; 
}

char *my_strncpy(char *dest, const char *src, int n){

  char *address;

  if((src == NULL)||(dest == NULL)){
    printf("invalid address\n");
    exit(1);
  }
  
  address = dest;   
  while((n--)&&(src != '\0')){
    *dest++ = *src++;
  }
  *dest = '\0';
  return address;
}
