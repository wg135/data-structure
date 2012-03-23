#include <stdio.h>
#include <stdlib.h>

int twond(int array[], int len);

int main(int argc, char *argv[]){

  int array[] = {1, -2, 3, 10, -4, 7, 2, -5};
  printf("2largest is %d\n", twond(array, sizeof(array)/sizeof(array[0])));
  
  return 0;
}

int twond(int array[], int len){

  int i;
  int max, secondmax;

  if((array == NULL)||(len == 0)||(len == 1))
    exit(1);

  max = secondmax = array[0];

  for(i=1; i<len;i++){
    if(max < array[i]){ //next element is greater than max
      secondmax = max;
      max = array[i];
    }
    else
      if(secondmax < array[i]) // next element is smaller than max but greater than secondmax
        secondmax = array[i];
  }
  
  return secondmax;
  
}
