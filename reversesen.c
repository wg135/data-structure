#include <stdio.h>
#include <stdlib.h>

char *reverse(const char *src);
void rever(char *begin, char *end);

int main(int argc, char *argv[]){
 
  const char *string = "i am a student";
  char *dst;
  dst = reverse(string);
  printf("%s\n", dst);
  free(dst);

  return 0;
}

char *reverse(const char *src){

  int len = 0;
  int len1;
  int i;
  char *dst;
  char *tmp;
  char *end1;
  
  if(src == NULL)
    return NULL;
  
  while(*src != '\0'){
    src++;
    len++;
  }
  src--;
  
 
  dst = (char *)malloc(len * sizeof(char));
  if(dst == NULL){
    printf("malloc error\n");
    exit(1);
  }
  for(i=0; i<len; i++)
    *dst++ = *src--;
  *dst = '\0';

  len1 = len; 
  while(len--)
    dst--;

  while(*dst != '\0'){
    tmp = dst;
    while((*dst != ' ')&&(*dst != '\0')){
      dst++;
    }
    if(*dst == '\0'){
      dst--;
    }
    end1 = dst;
    rever(tmp, end1);
    dst++;
  } 
    
  while(len1--)
    dst--;
  
  return dst;
}

  
void rever(char *begin, char *end){

  char tmp;

  if((begin == NULL)||(end == NULL))
    return;
  while(begin < end){
    tmp = *begin;
    *begin = *end;
    *end = tmp;
    begin++;
    end--;
  }
}
