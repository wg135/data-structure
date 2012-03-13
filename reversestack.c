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

STACK init_stack(unsigned int max_elements);
void dispose_stack(STACK S);
int is_stack_empty(STACK S);
int is_stack_full(STACK S);
void push(element_type x, STACK S);
element_type pop(STACK S);
void reverse_stack(STACK S);


int main(int argc, char *argv[]){

  int i;
  STACK S;
  
  S = init_stack(10);
  for(i=1; i<11; i++)
    push(i, S);

  reverse_stack(S);
  for(i=1; i<11; i++)
    printf("%d ", pop(S));
  printf("\n");

  return 0;
}


STACK init_stack(unsigned int max_elements){

  STACK S = NULL;
 
  S = (STACK)malloc(sizeof(struct stack_record));
  if(S == NULL){
    printf("stack init malloc error\n");
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

void dispose_stack(STACK S){
  
  if(S != NULL){
    free(S->stack_array);
    free(S);
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
    printf("stack is empty\n");
    exit(1);
  }
  else
    return S->stack_array[S->top_of_stack--];
}


void reverse_stack(STACK S){

  element_type i = 0;
  element_type array[S->stack_size];

  while(!is_stack_empty(S)){
    array[i++] = pop(S);  
  }
  for(i=0; i<S->stack_size; i++)
    push(array[i], S);
  
}






