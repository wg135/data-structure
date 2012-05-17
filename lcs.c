#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_lcs(char *str1, char *str2, int len1, int len2);
int max(int a, int b);

int main(int argc, char *argv[]){

  int len1, len2;
  char str1[] = "AGGTAB";
  char str2[] = "GXTXAYB";

  len1 = strlen(str1);
  len2 = strlen(str2);

  printf("%s and %s lcs is %d\n", str1, str2, get_lcs(str1, str2, len1, len2)); 
  
  return 0;
}

int get_lcs(char *str1, char *str2, int len1, int len2){

  int c[len1+1][len2+1];
  int i, j;
  
  for(i=0; i<=len1; i++)  //init
    for(j=0; j<=len2; j++)
      c[i][j] = 0;

  for(i=0; i<=len1; i++){
    for(j=0; j<=len2; j++){
      if((i==0)||(j==0))
        c[i][j] = 0;
      else if(*(str1+i) == *(str2+j))
        c[i][j] = c[i-1][j-1] + 1;
      else
        c[i][j] = max(c[i-1][j], c[i][j-1]);       
    }
  }
 
  return c[len1][len2]; 
}

int max(int a, int b){

  return (a > b)? a: b;
}
