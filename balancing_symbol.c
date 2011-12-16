#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef struct node *node_ptr;
typedef char elementype;

struct node{

  elementype element;
  node_ptr next;
};

typedef node_ptr STACK;

STACK creat_stack();
int is_empty(STACK S);
int top(STACK S);
void push(STACK S, elementype x);
int pop(STACK S);
void destory_stack(STACK S);

int main(int argc, char *argv[]){

  FILE *handle;
  char cn;
  STACK S1, S2, S3, S4;
  int err_s1 = 0, err_s2 = 0, err_s3 = 0, err_s4 = 0;

  if(argc != 2){
    printf("usage: ./name filename\n");
    exit(1);
  }
  
  S1 = creat_stack(); /* for ()*/
  S2 = creat_stack();  /* for {}*/
  S3 = creat_stack();  /* for []*/
  S4 = creat_stack();  /* for itself */ 

  /* open source file*/
  handle = fopen(argv[1], "r"); 
  if(!handle){
    perror("canot open source file\n");
    exit(1);
  }
  else
    printf("open source file successful\n"); 
  
  while(!feof(handle)){
    cn = fgetc(handle);
    switch(cn){
    case '(':
      push(S1, '(');  
      break;
    case ')':
      err_s1 = pop(S1);
      break;
    case '{':
      push(S2, '{');
      break;
    case '}':
     err_s2 = pop(S2);
      break;
    case '[':
      push(S3, '[');
      break;
    case ']':
      err_s3 = pop(S3);
      break;
    case '/':
      cn = fgetc(handle);
      if(cn == '*')
        push(S4, '*');
      break;
    case '*':
      cn = fgetc(handle);
      if(cn == '/')
        err_s4 = pop(S4);
      break;
    }
   if(err_s1){
     printf("miss '(' error\n");
     exit(1);
   }
   if(err_s2){
     printf("miss '{' error\n");
     exit(1);
   }
   if(err_s3){
     printf("miss '[' error\n");
     exit(1);
  }
   if(err_s4){
      printf("miss '/*'error\n ");
      exit(1);
   }
  }
 
  if(!(is_empty(S1))){
    printf("miss ')'\n");
  }
  if(!(is_empty(S2))){
    printf("miss '}'\n");
  }
  if(!(is_empty(S3))){
    printf("miss ']'\n");
  }
  if(!(is_empty(S4))){
    printf("miss '*/'\n");
  }
  
  if(is_empty(S1)&&is_empty(S2)&&is_empty(S3)&&is_empty(S4))
    printf("check okay\n");
  return 0;
}

int is_empty(STACK S)
{

  return (S->next == NULL);
}

STACK creat_stack()
{

  STACK S;
  
  S = (STACK)malloc(sizeof(struct node));
  if(S == NULL){
    printf("creat failed\n");
    exit(1);
  }
  else
    return S;
}

void push(STACK S, elementype x)
{

  node_ptr tmp_cell;
  
  tmp_cell = (node_ptr)malloc(sizeof(struct node)) ;
  if(tmp_cell == NULL){
    printf("push failed\n");
    exit(1);
  }
  else{
    tmp_cell->element = x;
    tmp_cell->next = S->next;
    S->next = tmp_cell;
  }  
}

int pop(STACK S)
{

  node_ptr first;

  if(is_empty(S)){
    //printf("empty stack");
    return 1;
  }
  else{
    first = S->next;
    S->next = S->next->next;
    free(first);
    return 0;
  }
}

void destory_stack(STACK S)
{

  while(!(is_empty(S))){
    pop(S);
  }
}








