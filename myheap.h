#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element_type;

struct heap_struct{

  unsigned int max_heap_size;
  unsigned int size;
  element_type *elements;
};

typedef struct heap_struct *PRIORITY_QUEUE;

PRIORITY_QUEUE creat_pq(unsigned int max_elements);
void heap_insert(element_type x, PRIORITY_QUEUE H);
int is_heap_full(PRIORITY_QUEUE H);
element_type delete_min(PRIORITY_QUEUE H);
int is_heap_empty(PRIORITY_QUEUE H);
void free_heap(PRIORITY_QUEUE H);

PRIORITY_QUEUE creat_pq(unsigned int max_elements){

  PRIORITY_QUEUE H;

  H =(PRIORITY_QUEUE)malloc(sizeof(struct heap_struct)) ;
  if(H == NULL){
    printf("init H faild\n");
    exit(1);
  }
  
  H->elements = (element_type *)malloc((max_elements + 1) * sizeof(element_type));
  if(H->elements == NULL){
    printf("init elements failed\n");
    exit(1);
  }

  H->max_heap_size = max_elements;
  H->size = 0;
  H->elements[0] = 0;

  return H;
}

void heap_insert(element_type x, PRIORITY_QUEUE H){

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

int is_heap_full(PRIORITY_QUEUE H){
  
  int i;

  if((H->size+1) < H->max_heap_size)
   i = 0;
  else
   i = 1;

  return i;
}

element_type delete_min(PRIORITY_QUEUE H){

  unsigned int i, child;
  element_type min_element, last_element;

  if(is_heap_empty(H)){
    printf("heap is empty\n");
    exit(1);
  }
  min_element = H->elements[1];
  last_element = H->elements[H->size--];
  
  for(i=1; i*2 <= H->size; i=child){
    child = 2 * i;
    if((child != H->size) &&(H->elements[child+1] < H->elements[child]))
      child++;

    if(last_element > H->elements[child])
      H->elements[i] = H->elements[child];
    else
      break;
    
  }
  H->elements[i] = last_element;

  return min_element;
}

int is_heap_empty(PRIORITY_QUEUE H){

  return(H->size == 0); 
}

void free_heap(PRIORITY_QUEUE H){
  
  free(H->elements);
  free(H);
}
