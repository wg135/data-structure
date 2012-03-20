#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void left1(char *s, int N, int K);
char *left2(char *s, int N, int K);
char *invert(char *start, char *end);

int main(int argc, char *argv[]){
 
  char s[] = "abcd1234";
  left1(s, 8, 4);
  puts(s);
  puts(left2(s, 8, 4));

  return 0;
  

}

void left1(char *s, int N, int K){

  char tmp;
  int i;

  if((N <= 0)||(K < 0))
    return;
 
  while(K--){
    tmp = s[0];
    for(i=0; i<N-1; i++)
      s[i] = s[i+1];
    s[N-1] = tmp;
  }
  
}

char *left2(char *s, int N, int K){

  invert(s, s+(K - 1));
  invert(s+K, s+(N-1));
  invert(s, s+(N-1));

  return s;
}

char *invert(char *start, char *end){

  char tmp;
  char *p = start;
  
  while(start != NULL && end != NULL && (start < end)){
    tmp = *start;
    *start = *end;
    *end = tmp;
    start++;
    end--;
  }
  
  return p;
}


