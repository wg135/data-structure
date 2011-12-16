#include <stdio.h>
#define random(x) (rand()%x)

void quick_sort(int test[], int num);
void q_sort(int test[], int left, int right);
int partition(int test[], int left, int right);
int select_pivot(int test[], int left, int right);
void swap(int *a, int *b);

int main(int argc, char *argv[]){

  int test_array[20];
  int i;
  
  for(i=0; i<20; i++){
    test_array[i] = random(100);
    printf("%d ", test_array[i]);
  }
  printf("\n");

  quick_sort(test_array, 20);

  for(i=0; i<20; i++)
    printf("%d ", test_array[i]);
  printf("\n");

  return 0;
}

void quick_sort(int test[], int num){
  
  q_sort(test, 0, num - 1);
}

void q_sort(int test[], int left, int right){

  int pi;

  if(left >= right)
   return;

  pi = partition(test, left, right);
  q_sort(test, left, pi-1);
  q_sort(test, pi+1, right); 
}

int partition(int test[], int left, int right){

  int p, store;
  int i;
 
  p = select_pivot(test, left, right);
  swap(&test[p], &test[right]);
  store = left;

  for(i=left; i<right; i++){
    if(test[i] <= test[right]){
      swap(&test[i], &test[store]);
      store++;
    }
  }
    swap(&test[store], &test[right]);
  return store;
}

int select_pivot(int test[], int left, int right){

  int center;
  
  center = (left + right) / 2; 
  if(test[left] > test[center]) 
    swap(&left, &center);
  if(test[left] > test[right])
    swap(&left, &right);
  if(test[center] > test[right])
    swap(&center, &right);

  return center;

}

void swap(int *a, int *b){

  int tmp;
  
  tmp = *a;
  *a = *b;
  *b = tmp; 
}

