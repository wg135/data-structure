#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CNT 256

char maxium(char *string);

int main(int argc, char *argv[]){

  char string[] = "test string";
  printf("%c\n", maxium(string));
  return 0;
}

char maxium(char *string){
  
  char *p;
  int array[CNT];
  int i, tmp = 0;
 
  for(i=0; i<CNT; i++)
    array[i] = 0;

  while(*string != '\0'){
    array[*string] += 1;
    string++;
  }
  
  for(i=0; i<CNT; i++){
    if(tmp < array[i])
      tmp = array[i];
  }
  for(i=0; i<CNT; i++)
    if(tmp == array[i])
     return i;
}
