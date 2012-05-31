#include <stdio.h>
#include <stdlib.h>


int subarray(int array[], int cnt);
void subarrayindex(int array[], int cnt);
int Max(int a, int b);

int main(int argc, char *argv[]){

  int array[10] = {31, -41, 59, 26, -53, 58, 97, -93, -23, 84};

  subarrayindex(array, sizeof(array)/sizeof(array[0]));
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

void subarrayindex(int array[], int cnt){

  int maxsofar = 0, maxsofar_old = 0;
  int maxend = 0;
  int i;
  int curr = 0, next = 0;
  
  for(i=0; i<cnt; i++){
    maxend = Max(maxend+array[i], 0);
    maxsofar = Max(maxsofar, maxend);
    if(maxsofar_old < maxsofar)
      next++;    //new sub array has greater value, next move
    maxsofar_old = maxsofar; 
    if(maxend == 0){//get 0, previous elements are throw away
      next++;
      curr = next;
    }

  }
  printf("betweend %d and %d\n", curr, next);
}

int Max(int a, int b){
  return (a>b)? a:b;
}
