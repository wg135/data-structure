#include <stdio.h>
#include <stdlib.h>

#define EMPTY_TOS (-1)

struct stack_record{

  unsigned int stack_size;
  int top_of_stack;
  int *stack_array;
};

typedef struct stack_record *STACK;

STACK init_stack(unsigned int max_elements);
void dispose_stack(STACK S);
int is_stack_empty(STACK S);
void make_stack_null(STACK S);
void push(int x, STACK S);
int is_stack_full(STACK S);
int pop(STACK S);
int top(STACK S);
int popseq(int num1[], int cnt1, int num2[], int cnt2);

int main(int argc, char *argv[]){

  int num1[5] = {1, 2, 3, 4, 5};
  int num2[5] = {4, 5, 3, 2, 1};
  int num3[5] = {4, 3, 5, 1, 2};

  if(popseq(num1, 5, num3, 5))
    printf("is sequence\n");
  else
    printf("not sequence\n");
}

int popseq(int num1[], int cnt1, int num2[], int cnt2){

  int i = 0, j = 1;
  STACK S;

  if((num1 == NULL)||(num2 == NULL)){ //empty array
    printf("empty array\n");
    exit(1);
  }

  if(cnt1 != cnt2){ //size of two array should be same
    printf("two array sizes are different\n");
    exit(1);
  }
  
  S = init_stack(cnt1);
  push(num1[0], S);

  for(j=1; j<cnt2; i++){
    if(j<cnt1){
      while(num2[i] != top(S)){
        push(num1[j++], S);
      }
      pop(S);
    }
  }
  for(i; i<cnt2; i++){
    if(num2[i] == top(S))
      pop(S);
    else{
     return 0;
    }
  }
  return is_stack_empty(S); 
}

STACK init_stack(unsigned int max_elements){

  STACK S;
  
  S = (STACK)malloc(sizeof(struct stack_record));
  if(S == NULL){
    printf("stack init malloc error\n");
    exit(1);
  }

  S->stack_array = (int *)malloc(sizeof(int) * max_elements);
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

void push(int x, STACK S){

  if(is_stack_full(S)){
    printf("stack is full\n");
    exit(1);
  }
  else
    S->stack_array[++S->top_of_stack] = x;
}

int is_stack_full(STACK S){

  return (S->stack_size == S->top_of_stack-1);
}

int pop(STACK S){

  if(is_stack_empty(S)){
    printf("stack empty\n");
    exit(1);
  }
  else
    return S->stack_array[S->top_of_stack--];
}

int top(STACK S){
  
  return S->stack_array[S->top_of_stack];
}
