/* reverse an array using recursion*/
#include <stdio.h>
#include <stdlib.h>

void reverse(int array[], int start, int end);

int main(int argc, char *argv[]){

  int i;
  int array[10];

  for(i=0; i<10; i++)
    array[i] = i;

  reverse(array, 0, 9);
  
  for(i=0; i<10; i++)
    printf("%d ", array[i]);
  printf("\n");

  return 0;

}

void reverse(int array[], int start, int end){

  int tmp;

  if(array == NULL){
    printf("array is invalied\n");
    exit(1);
  }

  if((start == end)||(start == end-1)) //odd number or even number
    return;

  tmp = array[start];
  array[start] = array[end];
  array[end] = tmp;
 
  reverse(array, start+1, end-1); //cannot use start++ end-- 
}
