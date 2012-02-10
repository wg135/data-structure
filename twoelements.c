#include <stdio.h>
#include <stdlib.h>

int sum2(int array[], int len, int num);

int main(int argc, char *argv[]){

  int array[] = {1, 2, 4, 7, 11, 15};
  if(sum2(array, sizeof(array)/sizeof(array[0]),15))
    printf("got\n");
  else
    printf("nothing\n");
 
  return 0;
}

int sum2(int array[], int len, int num){
 
  int index1, index2;
  int sum;
 
  index1 = 0;
  index2 = len-1;

  while(index1 < index2){
    if((array[index1]+array[index2])>num){
      index2--;
    }
    if((array[index1]+array[index2])<num){
      index1++;
    }
    if((array[index1]+array[index2] == num)){
      printf("%d + %d = %d\n", array[index1], array[index2], num);
      return 1;
    }
  }  
  return 0; 
}
