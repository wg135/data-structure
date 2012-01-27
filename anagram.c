#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int string_anagram(char *str1, char *str2);

int main(int argc, char *argv[]){

  char str1[] = "hello";
  char str2[] = "holle";

  if(string_anagram(str1, str2))
    printf("not anagram\n");
   else
    printf("anagram\n");

  return 0;
}

int string_anagram(char *str1, char *str2){

  int check[128];
  int i;
 
  for(i=0; i<128; i++)
    check[i] = 0;

  if((str1 == NULL)||(str2 == NULL)){
    printf("null string\n");
    exit(1);
  }

  if(strlen(str1) != strlen(str2))
    return -1;
 
  while(*str1 != '\0'){
    check[(int)*str1] += 1;
    str1++; 
  } 
  while(*str2 != '\0'){
    check[(int)*str2]  -= 1;
    str2++;
  } 

  for(i=0; i<128; i++){
    if(check[i] != 0)
      return -1;
  }
  
  return 0;

}
