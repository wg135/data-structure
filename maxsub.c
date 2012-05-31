#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Max(int a, int b);
int result(char string[]);

int main(int argc, char *argv[]){
  
  char string[] = "abcabcbb";
  char strin2[] = "bbbbbb";
  printf("%d\n", result(string));
   printf("%d\n", result(strin2));
  return 0;
}

int Max(int a, int b){
  return (a>b)? a : b;
}

int result (char string[]){

  int hash[26];
  int value = 0, curr = 0, prev = 0;

  memset(hash, 0, 26);
  while(string[curr] != '\0'){
    if(!hash[string[curr] - 'a']){
      hash[string[curr] - 'a'] = 1;
      curr++;
      value = Max(value, curr-prev);
    }
    else{
      memset(hash, 0, 26);
      prev++;
      curr = prev;
    }
  }
  return value;
}
