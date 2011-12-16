#include <stdio.h>
#include <stdlib.h>

typedef int element_type;

int binary_search(element_type A[], element_type x, int n);

int main(int argc, char *argv[]){

  element_type A[20];
  int i;

  for(i=0; i<20; i++){
     A[i] = i;
     printf("%d ", A[i]);
  } 
  printf("\n");

  if(binary_search(A, 10, 20))
    printf("10 is in the array\n");
  else
    printf("10 is not in the array\n");

  return 0;
}

int binary_search(element_type A[], element_type x, int n){

  int low, md, high;
  
  low = 0;
  high = n-1;

  while(low <=high){
    md = (low + high) / 2;
    if(x == A[md])
      return 1;
    if(x < A[md])
      high = md - 1;
    if(x > A[md])
      low = md + 1;
  }
  
  return 0;
  
}



