#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int string_match1(const char *str1, const char *str2);

int main(int argc, char *argv[]){

  const char str1[] = "abcdefg";
  const char str2[] = "def";

  if(string_match1(str1, str2))
    printf("%s has %s\n", str1, str2);
  
  return 0;

}

int string_match1(const char *str1, const char *str2){

  int len1, len2;
  int m, n;
  int result = 0;

  if((str1 == NULL) ||(str2 == NULL)){
    printf("string should not be empty\n");
    exit(1);
  }
  
  len1 = strlen(str1) - 1;
  len2 = strlen(str2) - 1;

  if(len1 < len2){
    printf("string 1 should longer than string 2\n");
    exit(1);
  } 

  for(m=0; m<(len1 - len2); m++){
    for(n=0; n<len2; n++){
      if(*(str1+m+n) == *(str2+n))
        ++result;
    }
    if(result == len2)
      return result;
    else
      result = 0;
  }

  return result; 
}
