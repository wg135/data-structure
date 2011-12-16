#include <stdio.h>
#include <stdlib.h>

typedef int element_type;

struct queue_record{

  unsigned int q_max_size;
  unsigned int q_rear;
  unsigned int q_front;
  unsigned int q_size;
  element_type *q_array;
};

typedef struct queue_record *QUEUE;

int is_empty(QUEUE Q){

  return (Q->q_size == 0);
}

void make_null(QUEUE Q){

  Q->q_size = 0;
  Q->q_front = 1;
  Q->q_rear = 0;
}

unsigned int succ(unsigned int value, QUEUE Q){

  if(++value == Q->q_max_size)
    value = 0;
  return value;
}

void enqueue(element_type x, QUEUE Q){

  if(is_full(Q)){
    printf("queue is full\n");
    exit(1);
  }
  else{
    Q->q_size++;
    Q->q_rear = succ(Q->q_rear, Q);
    Q->q_array[Q->q_rear] = x;
  }

}


int is_full(QUEUE Q){
  return (Q->q_size == Q->q_max_size);
}

element_type dequeue(QUEUE Q){

  element_type tmp;
  if(is_empty(Q)){
    printf("queue is empty\n");
    exit(1);
  }
  else{
    Q->q_size--;
    tmp = Q->q_array[Q->q_front];
    Q->q_front = succ(Q->q_front, Q);    
  }
 
  return tmp;

}

int main(int argc, char *argv[]){

  int i=0;
  int tmp;
  QUEUE Q = (QUEUE)malloc(sizeof(struct queue_record));
  Q->q_array = malloc(sizeof(element_type) * 10);
  Q->q_max_size = 10;
  make_null(Q);
  
  for(i=0; i<10; i++)
    enqueue(i, Q); 
 
   for(i=0; i<10; i++)
     printf("%d ", dequeue(Q)); 
   printf("\n");

  free(Q);
  return 0;
 



















}
