#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int  my_strstr(char *string, char *substring);

int main(int argc, char *argv[]){

  char *a = "abcdefg";
  char *b = "bc";
  
  if(my_strstr(a, b))
    printf("it has\n");
  return 0;
}

int my_strstr(char *string, char *substring){

  int len_str, len_substr, len;
  int i, j;

  if(string == NULL || substring == NULL)
   return 0;

  len_str = strlen(string);
  len_substr = strlen(substring);
  len = len_substr;
  if(len < 0)
   return 0;

  for(i=0; i<len_str; i++){
    for(j=0; j<len_substr; j++){
      if(substring[j] != string[i]){
        len =  len_substr;
        break;
      }
      else{
        len = len - 1;
        i++;
      }
    }
    if(len == 0)
    break;
  }
  return (!len); 
}
