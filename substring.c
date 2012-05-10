#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sub_string(const char *string1, const char *string2);

int main(int argc, char *argv[]){

  char str1[] = "defghikkkk";
  char str2[] ="efg";

  if(sub_string(str1, str2))
    printf("has\n");
  else
    printf("not has\n");

  return 0;
}

int sub_string(const char *string1, const char *string2){

  int len1, len2;
  int m, n;
  int result = 0;

  if((string1 == NULL)||(string2 == NULL)){
    return 0;
  }
  
  len1 = strlen(string1) - 1;
  len2 = strlen(string2) - 1; 
  
  if(len1 < len2)
    exit(1); 

  for(m=0;m<(len1-len2);m++){
    for(n=0; n<len2; n++){
      if(*(string1+m+n) == *(string2+n))
        ++result;
    }
    if(result == len2)
      return result;
    else
      result = 0;
  }

  return result;
  
}
