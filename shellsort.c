#include <stdio.h>
#define random(x) (rand()%x)

void shell_sort(int test[], int num);

int main(int argc, char *argv[]){

  int test_array[20];
  int i;
  
  for(i=0; i<20; i++){
    test_array[i] = random(100);
    printf("%d ", test_array[i]);
  }
  printf("\n");

  shell_sort(test_array, 20);
 
  for(i=0; i<20; i++){
    printf("%d ", test_array[i]);
  }
  printf("\n");
  return 0;
}

void shell_sort(int test[], int num){

  int gap = num/2;
  int i, j;
  int tmp;

  while(gap>= 1){
   for(i=gap; i<num; i+=gap){
     j = i - gap;
     tmp = test[i];
     while((j>=0)&&(tmp<test[j])){
       test[j+gap] = test[j];
       j -= gap;
     }
     test[j+gap] = tmp;
  }  
    gap /= 2;
  }
} 
