#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 100

typedef struct node *node_ptr;
typedef char elementype;

struct node{

  elementype element;
  node_ptr next;
};

typedef node_ptr STACK;
STACK creat_stack();
int is_empty(STACK S);
elementype top(STACK S);
void push(STACK S, elementype x);
int pop(STACK S);
void destory_stack(STACK S);
char* covert_postfix(const char *fixline, char *postline);

int main(int argc, char *argv[]){

  char *fixline = (char *)malloc(MAX * sizeof(char));
  if(fixline == NULL){
    printf("malloc fixline error\n");
    exit(1);
  }

  char *postline = (char *)malloc(MAX * sizeof(char));
  if(postline == NULL){
    printf("malloc postline error\n");
    exit(1);
  }


  if(argc != 2){
    printf("usage: ./name string\n");
    exit(1);
  }
 
  if(strlen(argv[1]) > 100){
    printf("expression should be less than 100 characters\n");
    exit(1);
  } 
  if(strcpy(fixline, argv[1]) == NULL){
    printf("copy error\n");
    exit(1);
  }
  
  covert_postfix(fixline, postline);
  printf("%s\n", postline);
  return 0;
  
}
  
char* covert_postfix(const char *fixline, char *postline){
 
  STACK S;
  int i = 0;
  char cn;
  
  S = creat_stack();
  
  while((cn = *fixline++) != '\0'){
    switch (cn){
      case '(':
        push(S, '(');
        break;

       
      case ')':
        while(top(S) != '('){
           *postline++ = top(S);
            pop(S);
        }
        pop(S);
        break;
  
 
      case '+':
      case '-':
        if(is_empty(S)){
          push(S, cn);
          break;
        }
        while(!is_empty(S)){
          if(top(S) != '('){
            *postline++ = top(S);
            pop(S);
          }
          else
            break;
        }
        push(S, cn);
        break;

    
      case '*':
      case '/':
        push(S, cn);
        break;



    default:
      if((isdigit(cn))||(islower(cn))||(isupper(cn))){
        *postline++ = cn;
        break;
        }
      }
  }
  while(!is_empty(S)){
    *postline++ = top(S);
    pop(S);
  }

  free(S);
  S = NULL;
  return postline;
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

elementype top(STACK S){

  if(is_empty(S)){
    printf("empty stack\n");
    exit(1);
  }
  else
    return S->next->element;
}
