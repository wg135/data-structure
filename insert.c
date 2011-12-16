#include <stdio.h>
#define random(x) (rand()%x)

void insertion(int test[], int num);

int main(int argc, char *argv[]){

  int test_array[20];
  int i;
  
  for(i=0; i<20; i++){
    test_array[i] = random(100);  
    printf("%d ", test_array[i]);
  }
  printf("\n");
  
  insertion(test_array, 20);
  
  for(i=0; i<20; i++){
    printf("%d ", test_array[i]);
  }
  printf("\n");
  return 0;
}

void insertion(int test[], int num){

  int i, j, tmp;
  
  for(i=1; i<num; i++){
    j = i - 1;
    tmp = test[i];
  while((j>=0)&&(tmp<test[j])){
    test[j+1] = test[j];
    j--;
  }
  test[j+1] = tmp;
}
} 
