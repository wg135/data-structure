#include <stdio.h>
#include <stdlib.h>

void triple(int array[], int num, int result);
int sort_function(const void *a, const void *b);

int main(int argc, char *argv[]){

  int array[] = {-1, 0, 1, 2, -1, -4};
  triple(array, sizeof(array)/sizeof(array[0]), 0);
  return 0;
}

void triple(int array[], int num, int result){

  int i, j, k;
  int sum;

  if(num < 2)
    return;
  i = 0;
  j = num-1;
  qsort((void *)array, num, sizeof(int), sort_function);
  for(k=2; k<num; k++){
    sum = result - array[k];
    while(i<j){
      if(((array[i] + array[j]) == sum)&&(i != k)){
	printf("%d + %d + %d = %d\n", array[i], array[j], array[k], result);
        i++;
        j--;
      }
      if(((array[i] + array[j]) > sum)&&(i != k))
        j--;
      if(((array[i] + array[j]) < sum)&&(i != k))
       i++;
      if(i == k)
        i++;
      if(j == k)
        j--;
    }
  }
}

int sort_function(const void *a, const void *b){
  if(*(int *)a > *(int *)b)
    return 1;
  else if(*(int *)a < *(int *)b)
    return -1;
  else
    return 0;
}
