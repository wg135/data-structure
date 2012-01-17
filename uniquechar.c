#include <stdio.h>
#include <stdlib.h>

void init_ascii(int array[], int size);
int check_uniq(char *string);

int main(int argc, char *argv[]){

  char *string = "hello world";  
  
  if(check_uniq(string) == -1)
    printf("not unique\n");
  else
    printf("unique\n");

  return 0;
}

void init_ascii(int array[], int size){

  int i;
  
  for(i=0; i<size; i++)
    array[i] = 0;
}

int check_uniq(char *string){
  
  int array[256];
  int i;

  init_ascii(array, sizeof(array)/sizeof(array[0]));
  while(*string != '\0'){
    array[(int)(*string++)] += 1;
  }
 
  for(i=0; i<256; i++){
    if(array[i] > 1)
      return -1;
  }
      return 0; 
}
