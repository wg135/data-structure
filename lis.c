#include <stdio.h>
#include <stdlib.h>

int get_lis(int array[], int len);

int main(int argc, char *argv[]){

  int array[] = {0, 22, 9, 33, 21, 50, 41, 60, 80};
  printf("lis is %d\n", get_list(array, sizeof(array)/sizeof(array[0])));
  return 0;
}

int get_list(int array[], int len){

  int i, j;
  int tmp[len];
  int max = 1;

  
  if(len == 1)
    return 1;

  // init the result array
  for(i=0; i<len; i++)
    tmp[i] = 1;
   
  for(i=1; i<len; i++){ //get the number
    for(j=0; j<i; j++){
      if((array[j] < array[i])&&(tmp[i] <tmp[j]+1))
        tmp[i] = tmp[j] + 1;
    }
  }
 
  //get the largest one 
  for(i=1; i<len; i++){
    if(tmp[i] > max)
      max = tmp[i];
  }
  
  return max;
}
