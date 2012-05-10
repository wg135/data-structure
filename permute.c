#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *string, int p, int q);
void permutation(char *string, int len);

int main(int argc, char *argv[]){
 
  char string[] = "abc";
  permutation(string, 0);

  return 0;
}

void swap(char *string, int p, int q){
  
  char tmp;
  
  tmp = *(string+p);
  *(string+p) = *(string+q);
  *(string+q) = tmp;
}

void permutation (char *string, int len){

  int i;

  if(len == strlen(string)){
    printf("%s\n", string);
    return;
  }
  else{
     for(i=len; i<strlen(string); i++){
        swap(string, i, len);
        permutation(string, len+1);
        swap(string, i, len);
     } 
  }
}
