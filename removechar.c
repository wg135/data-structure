#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CNT 256

char *remove1(char *str1, char *str2);

int main(int argc, char *argv[]){

  char str1[] = "test string";
  char str2[] = "mask";

  printf("%s\n", remove1(str1, str2));
  return 0; 
}

char *remove1(char *str1, char *str2){

  int array[CNT] = {0};
  int i;
  int curr = 0, next = 0;
  char *p;

  p = str1;
  while(*str2 != '\0'){
    array[*str2] += 1;
    str2++;
  }

  while(*(str1+next) != '\0'){
    if(array[str1[next]] == 0){
      *(str1+curr) = *(str1+next);
       curr++;
    }
    next++;
    
  } 
  *(str1+curr) = '\0';
  return str1;
}
