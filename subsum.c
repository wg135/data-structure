#include <stdio.h>
#include <stdlib.h>


int subarray(int array[], int cnt);
int Max(int a, int b);

int main(int argc, char *argv[]){

  int array[10] = {31, -41, 59, 26, -53, 58, 97, -93, -23, 84};

  printf("max sub sum is %d\n", subarray(array, sizeof(array)/sizeof(array[0])));
  return 0;
}

int subarray(int array[], int cnt){

  int maxsofar = 0;
  int maxend = 0;
  int i;

  for(i=0; i<cnt; i++){
    maxend = Max(maxend+array[i], 0);
    maxsofar = Max(maxsofar, maxend);
  }
  
  return maxsofar;
}

int Max(int a, int b){
  return (a>b)? a:b;
}
