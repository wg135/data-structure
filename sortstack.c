#include <stdio.h>
#include <stdlib.h>

#define EMPTY_TOS (-1)
#define random(x) rand()%x

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
STACK sort_stack(STACK S);
element_type top(STACK S);


int main(int argc, char *argv[]){

  int i;
  STACK S;

  S = init_stack(20);

  for(i=0; i<10; i++)
    push(random(100), S);

  sort_stack(S);

  for(i=0; i<10; i++)
    printf("%d ", pop(S));
  
  printf("\n");

  dispose_stack(S);
  
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

STACK sort_stack(STACK S){

  STACK S_add = NULL;
  element_type tmp;

  S_add = init_stack(S->stack_size);
  push(pop(S), S_add);
 
  while(!is_stack_empty(S)){
    tmp = pop(S);
    while((!is_stack_empty(S_add))&&(tmp < S_add->stack_array[S_add->top_of_stack])){
      push(pop(S_add), S);
    }
    push(tmp, S_add); 
  } 

  while(!is_stack_empty(S_add))
    push(pop(S_add), S);

  dispose_stack(S_add);
  return S;
  
}

element_type top(STACK S){
 
  if(is_stack_empty(S)){
    printf("stack is empty\n");
    exit(1);
  }
  else
    return S->stack_array[S->top_of_stack];
}






