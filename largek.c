#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element_type;
#define MIN_DATA -32765
#define random(x) (rand()%x)

struct heap_struct{

  unsigned int max_heap_size;
  unsigned int size;
  element_type *elements;
};

typedef struct heap_struct *HEAP;

HEAP creat_heap(unsigned int max_elements);
void heap_insert(element_type x, HEAP H);
int is_heap_full(HEAP H);
element_type delete_min(HEAP H);
int is_heap_empty(HEAP H);
void free_heap(HEAP H);
HEAP large(int array[], int len, unsigned int k);

int main(int argc, char *argv[]){

  int array[20];
  int i;
  HEAP H;
 
  for(i=0; i<20; i++){
    array[i] = random(200);
    printf("%d ", array[i]);
  }
  printf("\n");

  H = large(array, sizeof(array)/sizeof(array[0]), 5);
  for(i=1; i<=5; i++)
  printf("%d ", H->elements[i]);
  printf("\n");   

  free_heap(H);
  return 0;

}

HEAP creat_heap(unsigned int max_elements){

  HEAP H;

  H =(HEAP)malloc(sizeof(struct heap_struct));
  if(H == NULL){
    printf("init H malloc error\n");
    exit(1);
  }

  H->elements = (element_type *)malloc((max_elements + 1) *sizeof(element_type));
  if(H->elements == NULL){
    printf("init elements failed\n");
    exit(1);
  }
  
  H->max_heap_size = max_elements;
  H->size = 0;
  H->elements[0] = MIN_DATA;

  return H;
}

void heap_insert(element_type x, HEAP H){

  unsigned int i;
  
  if(is_heap_full(H)){
    printf("heap is full\n");
    exit(1);
  }
  else{
    i = ++H->size;
    while(H->elements[i/2] > x){
      H->elements[i] = H->elements[i/2];
      i /= 2;
    }
    H->elements[i] = x;
  }
}

int is_heap_full(HEAP H){

  return ((H->size + 1) > H->max_heap_size);
} 

element_type delete_min(HEAP H){

  unsigned int i, child;
  element_type min_element, last_element;

  if(is_heap_empty(H)){
    printf("heap is empty\n");
    exit(1);
  }
  min_element = H->elements[1];
  last_element = H->elements[H->size--];

  for(i=1; i*2 <=H->size; i=child){
    child = 2 * i;
    if((child != H->size)&&(H->elements[child+1] < H->elements[child]))
      child++;

    if(last_element > H->elements[child])
      H->elements[i] = H->elements[child];
     else
      break;
  }
  H->elements[i] = last_element;
  
  return min_element;
}

int is_heap_empty(HEAP H){
  
  return (H->size == 0);
}

void free_heap(HEAP H){

  free(H->elements);
  free(H);
}

HEAP large(int array[], int len, unsigned int k){

  HEAP H;
  int i, j,child;
  element_type min_element;
  
  if(k == 0){
    printf("0 heap\n");
    exit(1);
  }
 
  H = creat_heap(k);
  if(len <= k){
    for(i=0; i<len; i++)
      heap_insert(array[i], H);
  }
  else{
    for(i=0; i<k; i++)
      heap_insert(array[i], H);

    for(i=k; i<len;i++){
      if(H->elements[1] < array[i]){
        H->elements[1] = array[i];
        min_element = H->elements[1];

    for(j=1; j*2<k; j=child){
      child = 2*j;
      if((child != k)&&(H->elements[child+1] < H->elements[child]))
        child++;
      if(H->elements[j] > H->elements[child]){
        min_element = H->elements[child];
        H->elements[child] = H->elements[j];
        H->elements[j] = min_element;
      }
    }
      }
    }
} 
  return H;  
}
