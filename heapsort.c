#include <stdio.h>
#define random(x) (rand()%x)

void heap_sort(int test[], int num);
void build_heap(int test[], int num);
void swap(int *a, int *b);
void heapify(int test[], int i, int n);
void delete_heap(int test[], int num);

int main(int argc, char *argv[]){

  int test_array[20];
  int i;
  
  for(i=0; i<20; i++){
    test_array[i] = random(100);
    printf("%d ", test_array[i]);
  }
  printf("\n");
  
  heap_sort(test_array, 20);
 
  for(i=0; i<20; i++){
    printf("%d ", test_array[i]);
  }
  printf("\n");
  return 0;
}

void heap_sort(int test_array[], int num){

  int i;
  /*build the heap*/
  build_heap(test_array, num);

  /* delete the heap*/
 delete_heap(test_array, num);
}

void build_heap(int test[], int num){

  int i;
  for(i= num/2-1; i>=0; i--)
    heapify(test, i, num);
}

void swap(int *a, int *b){

  int tmp;
  tmp = *b;
  *b = *a;
  *a = tmp;
}

void heapify(int test[], int i, int n){

  int child;
  int tmp;

  for(tmp= test[i]; i*2 <n; i = child){
    child = 2 * i + 1;
    if((child != n)&&(test[child]<test[child+1]))
      child++;
    if(tmp < test[child]) 
      test[i] = test[child];
    else
      break;  
  } 
  test[i] = tmp;
}

void delete_heap(int test[], int num){

  int i;
  for(i=num-1; i>0; i--){
    swap(&test[i], &test[0]);
    heapify(test, 0, i-1);
  }
}
