#include <stdlib.h>
#include <stdio.h>
typedef struct node *node_ptr;
typedef int elementype;

struct node{

  elementype element;
  node_ptr next;
};

typedef node_ptr LIST;
typedef node_ptr position;

int main(int argc, char *argv[]){

  int i;
  int N = atoi(argv[1]);
  int M = atoi(argv[2]);
  
  if(argc != 3){

    printf("usage: ./program N M\n");
    exit(1);
  }
  LIST L = (position)malloc(sizeof(struct node));
  if(L == NULL){
    printf("malloc failed\n");
    exit(1);
  }
  position p, tmp;

  L->element = 1;
  L->next = NULL;
  tmp = L;

 for(i=2; i<=N; i++){
    p = (position)malloc(sizeof(struct node));
    p->element = i;
    p->next = NULL;
    tmp->next = p;
    tmp = tmp->next;        
  }
  tmp->next = L;
  
  
 while(tmp != tmp->next){

    for(i=1; i<M; i++)
      tmp = tmp->next;
    tmp->next = tmp->next->next;
    N--;

  }
  
printf("%d\n", tmp->element);  
   
}

