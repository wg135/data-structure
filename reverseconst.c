#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *reverse(const char *string);

int main(int argc, char *argv[]){

  const char *string = "hello world\n";
  char *dst;
  dst = reverse(string);
  printf("%s\n", dst);
  free(dst);
 
  return 0;
}

char *reverse(const char *string){

  int len = 0;
  int i;
  char *dst;

  if(string == NULL){
    return NULL;
  }
  while(*string != '\0'){
    string++;
    len++;
  }
  string--;
  dst = (char *)malloc((len)*sizeof(char));
  if(dst == NULL){
    printf("malloc error\n");
    exit(1);
  }
  for(i=0; i<len; i++){
    *dst++ = *string--;
  }
  *dst = '\0';
  while(len--)
   dst--;
  return dst;
  
}
