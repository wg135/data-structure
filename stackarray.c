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
void make_stack_null(STACK S);
void push (element_type x, STACK S);
int is_stack_full(STACK S);
element_type pop(STACK S);

int main(int argc, char *argv[]){

  int i;
  int array[20];
  STACK S;

  S = init_stack(30);
  for(i=0; i<20; i++){
   array[i] = random(100);
   push(array[i], S); 
   printf("%d ", array[i]);
  }
  printf("\n");

  for(i=0; i<20; i++){
    printf("%d ", pop(S));
  }
  printf("\n");

  dispose_stack(S);

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

void dispose_stack(STACK S){

  if(S != NULL){
    free(S->stack_array);
    free(S);
  }
}

int is_stack_empty(STACK S){

  return (S->top_of_stack == EMPTY_TOS);
}

void make_stack_null(STACK S){
 
  S->top_of_stack = EMPTY_TOS;
}


void push(element_type x, STACK S){

  if(is_stack_full(S)){
    printf("stack is full");
    exit(1);
  }
  else
   S->stack_array[++S->top_of_stack] = x;
}

int is_stack_full(STACK S){

  return (S->stack_size == S->top_of_stack-1);
}

element_type pop(STACK S){

  if(is_stack_empty(S)){
    printf("stack empty\n");
    exit(1);
  }
  else
    return S->stack_array[S->top_of_stack--];
}





