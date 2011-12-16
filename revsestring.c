#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse_string(char *p);

int main(int argc, char *argv[]){

  char p[] = "bcdefghi";

  reverse_string(p);
  printf("%s\n", p);

  return 0;
}

void reverse_string(char *p){

  int i, len;
  char c;

  len = strlen(p)-1;
  for(i=0; i<=len/2; i++){
    c = *(p+i);
    *(p+i) = *(p+len-i);
    *(p+len-i) = c;
}   
}
