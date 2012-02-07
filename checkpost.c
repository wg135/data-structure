#include <stdio.h>
#include <stdlib.h>

int checkpostorder(int array[], int len);

int main(int argc, char *argv[]){

  int array1[] = {5, 7, 6, 9, 11, 10, 8};
  int array2[] = {7, 4, 6, 5};
  if(checkpostorder(array1,7))
    printf("array1 is post order\n");
  else
    printf("array1 is not post order\n");
  if(checkpostorder(array2, 4))
    printf("array2 is post order\n");
  else
    printf("array2 is not post order\n");
 
  return 0;
}

int checkpostorder(int array[], int len){

  int i;
  int last;
  int left = 1, right = 1;

  if((len == 0)||(array == NULL))
    return 0;
  
  last = array[len - 1];
  for(i=0; i<len/2; i++){
    if(array[i]>last){
      return 0;
    }
  }
 
  for(i=len/2; i<len-1; i++){
    if(array[i] < last){
     return 0;
    }
  }

  if(len/2 >0){
    left = checkpostorder(array, len/2);
    right = checkpostorder(array+len/2, len/2);
  }

  return (left&&right);

  
    
    
}
