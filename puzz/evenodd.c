#include <stdio.h>

int main(int argc, char *argv[]){

  int number;
  
  printf("input number:\n");
  scanf("%d", &number);
  if(number%2 == 0)
    printf("%d is even\n", number);
  else
    printf("%d is odd\n", number);

  return 0;
}
