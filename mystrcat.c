#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strcat(char *dest, const char *src);
char *my_strncat(char *dest, const char *src, int n);

int main(int argc, char *argv[]){

  char *a = "hello world";
  char *b = " yes";
  char c[50] = "\0";

  my_strcat(c, a);
  printf("%s\n", c); 
  my_strncat(c, b, 2);
  printf("%s\n", c); 

  return 0; 
}

char *my_strcat(char *dest, const char *src){

  char *address;

  if((dest == NULL)||(src == NULL)){
    printf("NULL address\n");
    exit(1);
  }

  address = dest;
    while(*dest != '\0')
      ++dest;
    while((*dest++ = *src++) != '\0')
       ;
    return address;
  }        

char *my_strncat(char *dest, const char *src, int n){

  char *address;
  int i = 0;
  
  if((dest == NULL)||(src == NULL)){
    printf("NULL address\n");
    exit(1);
  }  
  address = dest;
  while(*dest != '\0')
    ++dest;
  while(((*dest++ = *src++) != '\0')&&(++i <n));
  return address;
  
}







