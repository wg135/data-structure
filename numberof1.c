#include <stdio.h>
#include <stdlib.h>

int solution1(int number);
int solution2(int number);
int solution3(int number);

int main(int argc, char *argv[]){

  int num = 3;
  int num2 = -3;

  printf("solution1: the number of 1 is %d\n", solution1(num));
  printf("solution2: the number of 1 is %d\n", solution2(num2));
  printf("solution3: the number of 1 is %d\n", solution3(num2));
  return 0;
}

int solution1(int number){ //only works when number >= 0

  int count = 0;

  while(number){
    if(number & 0x00000001)
      count += 1;
    number = number >> 1;
  }
  return count;
}

int solution2(int number){ //right shift, compare the left bit, can handle negative

  int count = 0;

  while(number){
    if(number & 0x80000000)
      count += 1;
    number = number << 1;
  }
  return count;
}

int solution3(int number){

  int count = 0;
  
  while(number){
    ++count;
    number = (number-1) & number;
  }

  return count;
}
