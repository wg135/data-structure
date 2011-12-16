#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char find_firstchar(char *string);

int main(int argc, char *argv[]){

  char *a = "aabbeddcfg";
   
  printf("first is %c\n", find_firstchar(a)); 
  
  return 0;
}

char find_firstchar(char *string){

  int hashtable[256];
  int i;
  char *key;
  
  key = string;
  for(i=0; i<255; i++)
    hashtable[i] = 0;

  while(*key != '\0'){
    hashtable[*key++]++;
  }   

  while(*string != '\0'){
    if(hashtable[*string]  == 1)
      return *string;

    string++;
  }
  return '\0';
}
