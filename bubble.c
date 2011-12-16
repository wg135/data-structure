#include <stdio.h>
#define random(x) (rand()%x)

void bubble_sort(int test[], int num);

int main(int argc, char *argv[]){

  int test_array[20];
  int i;
 
  for(i=0; i<20; i++){
    test_array[i] = random(100);
    printf("%d ", test_array[i]);
  }
  printf("\n");
  
  bubble_sort(test_array, 20);

  for(i=0; i<20; i++)
    printf("%d ", test_array[i]);
  printf("\n");

  return 0;
    
}
 
void bubble_sort(int test[], int num){

  int i, j;
  int tmp;
  
  for(i=num-1; i>=0; i--){
   for(j=0; j<=i-1; j++){
      if(test[j]> test[j+1]){
	tmp = test[j];
        test[j] = test[j+1];
        test[j+1] = tmp;
      }
    
    } 
  }
}
 
