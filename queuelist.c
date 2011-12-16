#include <stdio.h>
#include <stdlib.h>

typedef struct node *node_ptr;
typedef int element_type;

struct node{

  element_type element;
  node_ptr next;
};

typedef node_ptr QUEUE;
typedef node_ptr position;
static position head = NULL, tail = NULL;

int is_empty(position head){

  return (head == NULL);  
}

position new(element_type x, position link){

  position p = (position)malloc(sizeof(struct node));
  p->element = x;
  p->next = link;
  
  return p; 
}

void enqueue(QUEUE Q, element_type x){

  if(head == NULL){
    head = (tail = new(x, head));
    return;
  } 
  else{
    tail->next = new(x, tail->next);
    tail = tail->next;
  }
}

element_type dequeue(QUEUE Q){

  element_type tmp = head->element;
  position t = head->next;
  free(head);
  head = t;
  return tmp;  
}


int main(int argc, char *argv[]){

  QUEUE Q;
  int i;

  for(i=0; i<10; i++)
    enqueue(Q, i);

  for(i=0; i< 10; i++)
    printf("%d ", dequeue(Q));
  printf("\n");

}








