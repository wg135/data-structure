#include <stdio.h>
#include <stdlib.h>

int submax(int array[], int num);

int main(int argc, char *argv[]){

  int array[] = {1, -2, 3, 10, -4, 7, 2, -5};
  printf("max is %d\n", submax(array, sizeof(array)/sizeof(array[0])));
  
  return 0;
  
}

int submax(int array[], int num){

  int i;
  int currentvalue, maxvalue;
  
  currentvalue = maxvalue = 0;

  for(i=0; i<num; i++){
    currentvalue += array[i];
    if(currentvalue < 0)
      currentvalue = 0;
    if(currentvalue > maxvalue)
      maxvalue = currentvalue;     
  }
  
  if(maxvalue == 0){ //all elements are negative
    maxvalue = array[0];
    for(i=1; i<num; i++){
      if(maxvalue < array[i])
        maxvalue = array[i];
    }
  }
  
 return maxvalue; 
}
