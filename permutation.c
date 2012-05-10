#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void recursivepermute(char *str, int k);
void exchange(char *str, int p1, int p2);

int main(int argc, char *argv[]){
  char a[] = "abc";
  recursivepermute(a,0);
  return 0;
}

void recursivepermute(char *str, int k){

  int i;

  if(k == strlen(str)){
    printf("%s\n", str);
  }
  else{
    for(i=k; i<strlen(str); i++){//i is number of elements 
      exchange(str, k, i);
      recursivepermute(str, k+1);
      exchange(str, k, i);  //restore
    }
  } 
}

void exchange(char *str, int p1, int p2){

  char tmp;

  tmp = str[p1];
  str[p1] = str[p2];
  str[p2] = tmp; 
}
