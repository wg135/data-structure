#include <stdio.h>
#include <stdlib.h>

int my_cmp(const char *s1, const char *s2);
int my_ncmp(const char *s1, const char *s2, int n);

int main(int argc, char *argv[]){

  char *s1 = "abcdef";
  char *s2 = "abcdeF";
  int i;
  
  i = my_ncmp(s1, s2, 7);
  
  if(i == 0)
    printf("%s equals to %s\n", s1, s2);
  if(i > 0)
    printf("%s greater than %s\n", s1, s2);
  else
    printf("%s less than %s\n", s1, s2);
  
  return 0;
 
}

int my_cmp(const char *s1, const char *s2){

  while((*s1 == *s2)&&(*s1 != '\0')){
    s1++;
    s2++;
  }
  
  return *s1 - *s2;
}

int my_ncmp(const char *s1, const char *s2, int n){

  int i = 0;
 
  if(n <= 0)
    return 0;
  else{
    while((*s1 == *s2)&&(*s1 != '\0')&&(i++<n)){
      s1++;
      s2++;
    }
    return *s1 - *s2;
  }
   
}
