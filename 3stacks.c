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
void push(element_type x, unsigned int stack_num, element_type buffer[], int stack_pointer[]);
int is_stack_full(STACK S);
element_type pop(unsigned int stack_num, element_type buffer[], int stack_pointer[]);

int main(int argc, char *argv[]){

  int buffer[30];
  int stack_pointer[3] = {0, 1, 2};
  int i;

  for(i=0; i<30; i++)
    buffer[i] = 0;

  push(1, 1, buffer, stack_pointer);
  push(2, 2, buffer, stack_pointer);

  for(i=0; i<30; i++)
    printf("%d ", buffer[i]);

  printf("\n");

  return 0;

}

STACK init_stack(unsigned int max_elements){

  STACK S;

  S = (STACK)malloc(sizeof(struct stack_record));
  if(S == NULL){
    printf("init stack malloc error\n");
    exit(1);
  } 
  
  S->stack_array = (element_type *)malloc(sizeof(element_type) * max_elements);

  S->top_of_stack = EMPTY_TOS;
  S->stack_size = max_elements;

  return S;
}

void dispose_stack(STACK S){

  free(S->stack_array);
  free(S);
}

int is_stack_empty(STACK S){

  return (S->top_of_stack == EMPTY_TOS); 
}

void make_stack_null(STACK S){

  S->top_of_stack = EMPTY_TOS;
}

void push(element_type x, unsigned int stack_num, element_type buffer[], int stack_pointer[]){
  
  if(stack_num == 1){
    buffer[stack_pointer[0]] = x;
    stack_pointer[0] += 3;
  }
  if(stack_num == 2){
    buffer[stack_pointer[1]] = x;
    stack_pointer[1] += 3;
  }
  if(stack_num == 3){
    buffer[stack_pointer[2]] = x;
    stack_pointer[2] += 3;
  }

 
}

int is_stack_full(STACK S){
  return (S->top_of_stack == S->stack_size -1);
}


element_type pop(unsigned int stack_num, element_type buffer[], int stack_pointer[]){

  element_type tmp;

  if(stack_num == 1){
    tmp = buffer[stack_pointer[0]];
    stack_pointer[0] -= 3;  
  }
  if(stack_num == 2){
    tmp = buffer[stack_pointer[1]];
    stack_pointer[1] -= 3;
  }
  if(stack_num == 3){
    tmp = buffer[stack_pointer[2]];
    stack_pointer[2] -= 3;
  }

  return tmp;
}





