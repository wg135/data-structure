#include <stdio.h>
#include <stdlib.h>

int three_sum(int array[], int num, int target);
int sort_function(const void *a, const void *b);
int abs(int a);

int main(int argc, char *argv[]){

  int array[] = {-1, 2, 1, -4};
  printf("close 1 is %d\n", three_sum(array, sizeof(array)/sizeof(array[0]), 1));
  return 0;

}

int three_sum(int array[], int num, int target){

  int i, j, k;
  int sum, tmp1, tmp2;

  if((array == NULL)||(num < 3))
    exit(1);
  i =0;
  j = num-1;
 
  qsort((void *)array, num, sizeof(int), sort_function);
  for(k=2; k<num; k++){
    sum = target - array[k];
    tmp2 = target;
    while(i<j){
      if(((array[i]+array[j])==sum)&&(i != k))
        return target;
      if(((array[i]+array[j])>sum)&&(i != k)){
        tmp1 =sum - (array[i] + array[j]);
        if(abs(tmp2) > abs(tmp1))
          tmp2 = tmp1;
         j--;
      } 
      if(((array[i]+array[j])<sum)&&(i != k)){
        tmp1 =sum - ( array[i] + array[j]);
        if(abs(tmp2) > abs(tmp1))
          tmp2 = tmp1;
          i++;
      }
      if(i== k)
        i++;
      if(j == k)
        j--;
    }
    return tmp2 + array[k];
  }
  
}

int sort_function(const void *a, const void *b){

  if(*(int *)a > *(int *)b)
    return 1;
  if(*(int *)a < *(int *)b)
    return -1;
  else
    return 0;
}

int abs(int a){
  if(a > 0)
    return a;
  else
    return (0 - a);
}
