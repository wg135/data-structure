#include <stdio.h>
#include <stdlib.h>

#define EMPTY_TOS (-1)
#define random(x) rand()%x

typedef int element_type;
typedef struct list_node *node_ptr;
typedef unsigned int INDEX;

struct list_node{

  element_type element;
  node_ptr next;
};

typedef node_ptr STACK;
typedef node_ptr position;

struct stack_set{

  unsigned int stack_size; //sub stack number in stack
  INDEX current_stack; // current index in working sub stack
  unsigned int capcaity;  // sub stack capcaity
  unsigned int stack_ptr; //woring sub stack
  STACK *the_stacks;     
};

typedef struct stack_set * STACK_SET;

STACK_SET init_stack(unsigned int stack_size);
void push(element_type x, STACK_SET S);
void pop(STACK_SET S);

int main(int argc, char *argv[]){

  STACK_SET S;
  
  S = init_stack(5);
  push(1, S);
  push(2, S);
  push(3, S);
  push(4, S);
  push(5, S);
  push(6, S);
  
  pop(S);

  return 0; 
  
}

STACK_SET init_stack(unsigned int stack_size){

  STACK_SET S;
  int i;

  S = (STACK_SET)malloc(sizeof(struct stack_set));
  if(S == NULL){
    printf("malloc S error\n");
    exit(1);
  }
  
  S->stack_size = stack_size;
  S->current_stack = 0;
  S->stack_ptr = 0;
  S->capcaity = 5;

  S->the_stacks = (position *)malloc(sizeof(STACK) * S->stack_size);
  if(S->the_stacks == NULL){
    printf("malloc S stacks error\n");
    exit(1);
  }
 
  for(i=0; i<S->stack_size; i++){
    S->the_stacks[i] = (STACK)malloc(sizeof(struct list_node));
    if(S->the_stacks[i] == NULL){
      printf("malloc list header error\n");
      exit(1);
    }
    else{
      S->the_stacks[i]->element = i;
      S->the_stacks[i]->next = NULL;
    }
  }

  return S;    
}

void push(element_type x, STACK_SET S){

  position new_cell;
  STACK S_sub;

  new_cell = (position)malloc(sizeof(struct list_node));
  if(new_cell == NULL){
    printf("push new cell malloc error\n");
    exit(1);
  }
  else{
    if(S->current_stack == S->capcaity - 1){
      S->current_stack = 0;
      S->stack_ptr += 1;
      S_sub = S->the_stacks[S->stack_ptr];
      new_cell->next = S_sub->next;
      new_cell->element = x;
      S_sub->next = new_cell;      
    }
    else{
      S->current_stack += 1;
      S_sub = S->the_stacks[S->stack_ptr];
      new_cell->next = S_sub->next;
      new_cell->element = x;
      S_sub->next = new_cell;
    }
  }

}

void pop(STACK_SET S){
 
  STACK S_sub;
  position tmp;

  if(S->current_stack == 0){
    S->stack_ptr -= 1;
    S->current_stack = S->capcaity - 1;
    S_sub = S->the_stacks[S->stack_ptr];
    tmp = S_sub->next;
    S_sub->next = S_sub->next->next;
    free(tmp);
  }
  else{
    S->current_stack -= 1;
    S_sub = S->the_stacks[S->stack_ptr];
    tmp = S_sub->next;
    S_sub->next = S_sub->next->next;
    free(tmp);
  }   
}




