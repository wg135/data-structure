#include <stdio.h>
#include <stdlib.h>

char* mystrstr(const char *string, const char *substr);

int main(int argc, char *argv[]){
  char string[] = "abcdefgh";
  char substr[] = "cde";
  printf("%s\n", mystrstr(string, substr));
  return 0;
}

char* mystrstr(const char *string, const char *substr){

  char *begin, *p1, *p2;

  p1 = (char *) string;
  if(substr == NULL)
    return p1;

  while(*p1 != '\0'){
    begin = p1;
    p2 = (char *)substr;
    while(p1&&p2&&(*p1==*p2)){
       p1++;
       p2++;
    }
    if(*p2 == '\0')
      return begin;
    p1 = begin+1;
  }
  return NULL;
}
