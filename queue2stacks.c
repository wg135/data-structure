#include <stdio.h>
#include <stdlib.h>

#define EMPTY_TOS (-1)

typedef int element_type;

struct stack_record{

  unsigned int stack_size;
  int top_of_stack;
  element_type *stack_array;
};

typedef struct stack_record *STACK;

struct queue_record{

  STACK S1;
  STACK S2;
};

typedef struct queue_record *QUEUE;

STACK init_stack(unsigned int max_elements);
QUEUE init_queue(unsigned int queue_size);
void dispose_stack(STACK S);
void dispose_queue(QUEUE Q);
int is_stack_empty(STACK S);
int is_stack_full(STACK S);
void push(element_type x, STACK S);
element_type pop(STACK S);
void enqueue(element_type x, QUEUE Q);
element_type dequeue(QUEUE Q);


int main(int argc, char *argv[]){

  QUEUE Q;
  int i;

  Q = init_queue(8);
 
  for(i=0; i<6; i++){
    enqueue(i, Q);
  }
  
  for(i=0; i<6; i++){
    printf("%d ", dequeue(Q));
  }
  printf("\n");
   

  dispose_queue(Q);

  return 0;

}

STACK init_stack(unsigned int max_elements){

  STACK S;

  S = (STACK)malloc(sizeof(struct stack_record));
  if(S == NULL){
    printf("Stack init malloc error\n");
    exit(1);
  } 

  S->stack_array = (element_type *)malloc(sizeof(element_type) * max_elements);
  if(S->stack_array == NULL){
    printf("stack array malloc error\n");
    exit(1);
  }

  S->top_of_stack = EMPTY_TOS;
  S->stack_size = max_elements;

  return S;
}

QUEUE init_queue(unsigned int queue_size){

  QUEUE Q;
  
  if(queue_size == 0){
    printf("invalid queue size\n");
    exit(1);
  }

  Q = (QUEUE)malloc(sizeof(struct queue_record));
  if(Q == NULL){
    printf("queue init malloc error\n");
    exit(1);
  }
  
  Q->S1 = init_stack(queue_size/2);
  Q->S2 = init_stack(queue_size/2);
  
  return Q; 
  
}

void dispose_stack(STACK S){

  if(S != NULL){
    free(S->stack_array);
    free(S);
  }
}

void dispose_queue(QUEUE Q){

  if(Q != NULL){
   // dispose_stack(Q->S1);
    //dispose_stack(Q->S2);
    free(Q);
  }    
}

int is_stack_empty(STACK S){

  return (S->top_of_stack == EMPTY_TOS);
}


int is_stack_full(STACK S){

  return (S->stack_size == S->top_of_stack - 1); 
}

void push(element_type x, STACK S){

  if(is_stack_full(S)){
    printf("stack is full\n");
    exit(1);
  }
  else
    S->stack_array[++S->top_of_stack] = x;
}

element_type pop(STACK S){

  if(is_stack_empty(S)){
    printf("stack empty\n");
    exit(1);
  }
  else
    return S->stack_array[S->top_of_stack--];
}

void enqueue(element_type x, QUEUE Q){

  //both S1 and S2 are full
  if(is_stack_full(Q->S1)&&(is_stack_full(Q->S2))){
    printf("queue is full\n");
    exit(1);
  }
 
  // S1 is full while S2 is not 
  if((is_stack_full(Q->S1))&&(!is_stack_full(Q->S2))){
    while(!is_stack_full(Q->S2)){
      push(pop(Q->S1), Q->S2);
    }
    
    push(x, Q->S1);
  }
  
  if((!is_stack_full(Q->S1))&&(!is_stack_full(Q->S2))){
    push(x, Q->S1);
  }
}

element_type dequeue(QUEUE Q){

  // both S1 and S2 are empty
  if((is_stack_empty(Q->S1))&&(is_stack_empty(Q->S2))){
    printf("queue is empty\n");
    exit(1);
  }
  
 
  if(!is_stack_empty(Q->S2))
    return (pop(Q->S2));
 
  if((!is_stack_empty(Q->S1)) && is_stack_empty(Q->S2)){
    while(!is_stack_empty(Q->S1)){
      push(pop(Q->S1), Q->S2);
   }
  return(pop(Q->S2));
  }

}


