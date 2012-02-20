#include <stdio.h>
#include <stdlib.h>

#define INT_MIN (-2147483648)
#define INT_MAX (2147483647)

int main(int argc, char *argv[]){

  char str[] = "-345";
  printf("%d\n", my_atoi(str));
  return 0;

}

int my_atoi(const char *s){
  
  int sign;
  int limit;
  int total = 0;

  if((s == NULL)&&(*s == '\0')){
    printf("illegal input\n");
    exit(1);
  }
  if(*s == '+'){
    s++;
    sign = 0;
  }
  if(*s == '-'){
    s++;
    sign = -1;
  }

  while(*s != '\0'){
    total = total * 10 + (*s - '0');
    s++;
  }
  
  return ((sign== -1)? total * sign: total);
  
}
