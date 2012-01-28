#include <stdio.h>
#include <stdlib.h>

int maxnum(int array[], int num);

int main(int argc, char *argv[]){

  int array[] = {1, 1, 1, 3, 3, 3, 3, 4, 4, 1, 1};
  int d;

  d =  maxnum(array, sizeof(array)/sizeof(array[0]));

  printf("the number is %d\n", d);

  return 0;
  
}

int maxnum(int array[], int num){

  int tmp, counter, maxcounter, i, max1;
  
  tmp = array[0];
  counter= 1;
  maxcounter = 1;
  max1 = tmp;
  
  for(i=1; i<num; i++){
    if(tmp == array[i]){
      ++counter;
      if(maxcounter < counter){
        maxcounter = counter;
        max1= array[i];
      }
    }
    else{
      tmp = array[i];
      counter = 1;
    }
  }
  
  return max1;  
}
