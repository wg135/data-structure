#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strcpy(char *dest, const char *source);

int main(int argc, char *argv[]){

  int len;
  char *a = "abcdefg";
  
  len = strlen(a);
  char *b = (char *)malloc(len * sizeof(char));
  if(b == NULL){
    printf("out of space\n");
    exit(1);
  }
  
  b = my_strcpy(b, a);
  printf("%s\n", b);
  free(b);
  return 0;
}

char *my_strcpy(char *dest, const char *source){

  char *address;

  if(dest == source)
    return dest;

  if((dest == NULL)||(source == NULL)){
    printf("address is NULL\n");
    exit(1);
  }
  address = dest;
  
  while((*dest++ = *source++) != '\0');
  return address;  
}
