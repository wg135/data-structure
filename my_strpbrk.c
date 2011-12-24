#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *mystrpbrk(const char *src, const char *set);

int main(int argc, char *argv[]){

  char *src = "abcdefg";
  char *set = "cde";

  printf("%s\n", mystrpbrk(src, set));
  
  return 0;
}

char *mystrpbrk(const char *src, const char *set){

  const char *address;

  if((src == NULL)||(set == NULL)){
    printf("address is NULL\n");
    return 0;
  }
  
  while(*src != '\0'){
    address = set;
    while(*address != '\0'){
      if(*src == *address)
        return (char *)src;
      else
        ++address;
    }
    ++src;
  }
  return NULL;

}
