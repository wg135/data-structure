#include <stdio.h>
#include <stdlib.h>

#define random(x) (rand()%x)

typedef struct btree_node *btree_ptr;
typedef int element_type;
typedef struct stack_node *stack_ptr;
typedef struct queue_node *queue_ptr;

struct btree_node{

  element_type element;
  btree_ptr left;
  btree_ptr right;
};

struct stack_node{

  btree_ptr node;
  stack_ptr next;  
};

struct queue_record{

  unsigned int q_max_size;
  unsigned int q_rear;
  unsigned int q_front;
  unsigned int q_size;
  btree_ptr *q_array;    
};

typedef btree_ptr BTREE;
typedef stack_ptr STACK;
typedef btree_ptr TREE_NODE;
typedef stack_ptr STACK_NODE;
typedef struct queue_record *QUEUE;


BTREE init_tree();
BTREE creat_tree(element_type *array, int total, BTREE T);
TREE_NODE bt_insert(element_type element, BTREE T);
BTREE find_tree(element_type element, BTREE T);
TREE_NODE find_min(BTREE T);
TREE_NODE find_max(BTREE T);
TREE_NODE tree_delete(element_type element, BTREE T);
void free_tree(BTREE T);
int height_recursive(BTREE T);
void preorder_recursive(BTREE T);
void inorder_recursive(BTREE T);
void postorder_recursive(BTREE T);
void preorder_norecursive(BTREE T);
void inorder_norecursive(BTREE T);
void postorder_norcursive(BTREE T);
void levelorder(BTREE T);
void visit(element_type element);
STACK creat_stack();
int is_stack_empty(STACK S);
TREE_NODE top_stack(STACK S);
void push(TREE_NODE node, STACK S);
void pop(STACK S);
void free_stack(STACK S);
int is_queue_empty(QUEUE Q);
void make_queue_null(QUEUE Q);
unsigned int succ(unsigned int value, QUEUE Q);
void enqueue(TREE_NODE x, QUEUE Q);
int is_queue_full(QUEUE Q);
TREE_NODE dequeue(QUEUE Q);
QUEUE queue_init();
void output_leaf_recursive(BTREE T);
void output_leaf_norecursive(BTREE T);
void exchange_recursive(BTREE T);
void exchange_norecursive(BTREE T);
void visit(element_type element){

  printf("%d ", element);
}

BTREE init_tree(){

  BTREE T = (TREE_NODE)malloc(sizeof(struct btree_node));
  if(T== NULL){
    printf("out of space\n");
    exit(1);
  }
  else{
    T->left = NULL;
    T->right = NULL;
  }

  return T; 
}
BTREE creat_tree(element_type *array, int total, BTREE T){  
 
  int i;
  BTREE p;
  p = T;

  for(i=0; i<total; i++)
    bt_insert(*(array+i),p);
  if(T->left != NULL){
    free(T);
    T = T->left;
  }
  else{
    free(T);
    T = T->right; 
  }
  return T;   
}

TREE_NODE bt_insert(element_type element, BTREE T){
 
  if(T == NULL){
    T = (TREE_NODE)malloc(sizeof(struct btree_node));
    if(T == NULL){
      printf("out of space\n");
      exit(1);
    }
    else{
      T->element = element;
      T->left = NULL;
      T->right = NULL;
    }
    
  }
  else
  if(element < T->element){
    T->left = bt_insert(element, T->left);
  }
  else
  if(element > T->element){
    T->right = bt_insert(element, T->right);
  }
  return T;
}

BTREE find_tree(element_type element, BTREE T){

  if( T == NULL)
    return NULL;
  if(element < T->element)
    return(find_tree(element, T->left));
  else 
    if(element > T->element)
      return(find_tree(element, T->right));
  else
    return T;
}

TREE_NODE find_min(BTREE T){

  if(T == NULL)
    return NULL;
  else
    if(T->left == NULL)
      return T;
    else
      return(find_min(T->left));
}

TREE_NODE find_max(BTREE T){

  if( T != NULL)
    while(T->right != NULL)
      T = T->right;
  return T;
}

TREE_NODE tree_delete(element_type element, BTREE T){
  
  TREE_NODE tmp, child;
 
  if(T == NULL){
    printf("element not found\n");
    exit(1);
  }
  else
    if(element < T->element)
      T->left = tree_delete(element, T->left);
    else
      if(element > T->element)
        T->right = tree_delete(element, T->right);
      else
      if(T->left && T->right){
        tmp = find_min(T->right);
        T->element = tmp->element;
        T->right = tree_delete(T->element, T->right);
      }
      else{
        tmp = T;
        if(T->left == NULL)
          child = T->right;
        if(T->right == NULL)
          child = T->left;

      free(tmp);

    return child;
    }

  return T;
}

int height_recursive(BTREE T){

  int height_l, height_r;
  
  if(T ==NULL)
    return -1;
  height_l = height_recursive(T->left);
  height_r = height_recursive(T->right);
  if(height_l > height_r)
    return height_l + 1;
  else
    return height_r + 1;
}  

void preorder_recursive(BTREE T){
  
  if(T != NULL){
    visit(T->element);
    preorder_recursive(T->left);
    preorder_recursive(T->right);
  }
}

void inorder_recursive(BTREE T){
  
  if(T != NULL){
    inorder_recursive(T->left);
    visit(T->element);
    inorder_recursive(T->right);
  }
} 

void postorder_recursive(BTREE T){

  if(T != NULL){
    postorder_recursive(T->left);
    postorder_recursive(T->right);
    visit(T->element);
  }
}

void preorder_norecursive(BTREE T){
 
  STACK S = creat_stack();
  while((T != NULL)||(!is_stack_empty(S))){
    if(T != NULL){
      visit(T->element);
      push(T, S);
      T = T->left;
    }
    else{
      T = top_stack(S);
      T = T->right;
      pop(S);
    }
 }

  free_stack(S); 
}

void inorder_norecursive(BTREE T){

  STACK S = creat_stack();
  while((T != NULL)||(!is_stack_empty(S))) {
    if(T != NULL){
      push(T, S);
      T = T->left;
    }
    else{
      T = top_stack(S);
      if(T != NULL){
        visit(T->element);
        pop(S);
        T = T->right;  
      }
   } 
    
  }

  free_stack(S);
}

void postorder_norcursive(BTREE T){

  int sign;
  STACK S = creat_stack();
  TREE_NODE tmp = NULL;
  while((T != NULL)||(!is_stack_empty(S))){
     while(T != NULL){
        push(T, S);
        T = T->left;      
     }
     sign = 1;
     while((sign)){
       T = top_stack(S);
       if(T == NULL)
         break;
       if((T->right == tmp)||(T->right == NULL)){
         visit(T->element);
         tmp = top_stack(S);
         pop(S);
       }
       else{
         T = T->right;
         sign = 0;
       }

     }
  }

  free_stack(S);
}
  
void levelorder(BTREE T){
  
  TREE_NODE tmp;
  QUEUE Q = queue_init();

  enqueue(T, Q);
  while(!is_queue_empty(Q)){
    tmp = dequeue(Q);
    visit(tmp->element);    
    if(tmp->left)
      enqueue(tmp->left, Q);
    if(tmp->right)
      enqueue(tmp->right, Q);
  }

  free(Q); 

}

STACK creat_stack(){
  
  STACK S;
  S = (STACK)malloc(sizeof(struct stack_node));
  if(S == NULL){
    printf("S init malloc\n");
    exit(1);
  }
  
  return S;
}

int is_stack_empty(STACK S){

  return(S->next == NULL);
}

TREE_NODE top_stack(STACK S){

  if(is_stack_empty(S)){
    return NULL;
  }
  else
    return ((TREE_NODE )S->next->node);
}

void push(TREE_NODE node, STACK S){

  stack_ptr tmp_cell;
  
  tmp_cell = (stack_ptr)malloc(sizeof(struct stack_node));
  if(tmp_cell == NULL){
    printf("push malloc failed\n");
    exit(1);
  }
  else{
    tmp_cell->node = node;
    tmp_cell->next = S->next;
    S->next = tmp_cell;
  }   
}

void pop(STACK S){

  stack_ptr first_cell;
  
  if(is_stack_empty(S)){
    printf("empty stack\n");
    exit(1);
  }
  else{
    first_cell = S->next;
    S->next = S->next->next;
    free(first_cell);
  }
  
}

void free_tree(BTREE T){
  
  if(T == NULL){
    free_tree(T->left);
    free_tree(T->right);
    free(T);
  }
  
}

void free_stack(STACK S){
  
  free(S);
  S = NULL;   
}

int is_queue_empty(QUEUE Q){

  return (Q->q_size == 0);
}

void make_queue_null(QUEUE Q){

  Q->q_size = 0;
  Q->q_front = 1;
  Q->q_rear = 0;
}

unsigned int succ(unsigned int value, QUEUE Q){

  if(++value == Q->q_max_size)
    value = 0;
  return value;
}

void enqueue(TREE_NODE x, QUEUE Q){

  if(is_queue_full(Q)){
    printf("queue is full\n");
    exit(1);
  }
  else{
    Q->q_size++;
    Q->q_rear = succ(Q->q_rear, Q);
    Q->q_array[Q->q_rear] = x;
  }

}

int is_queue_full(QUEUE Q){
  return (Q->q_size == Q->q_max_size);
}

TREE_NODE dequeue(QUEUE Q){

  TREE_NODE tmp;
  if(is_queue_empty(Q)){
    printf("queue is empty\n");
    exit(1);
  }
  else{
    Q->q_size--;
    tmp = Q->q_array[Q->q_front];
    Q->q_front = succ(Q->q_front, Q);
  }

  return tmp;

}


QUEUE queue_init(){

  QUEUE Q = (QUEUE)malloc(sizeof(struct queue_record));
  Q->q_array = malloc(sizeof(struct btree_node) * 20);
  if(Q->q_array == NULL){
    printf("q array malloc error\n");
    exit(1);
  }
  Q->q_max_size = 20;
  make_queue_null(Q);
  
  return Q;

}

void output_leaf_recursive(BTREE T){

  if(T != NULL){
    if((T->left == NULL)&&(T->right == NULL))
      visit(T->element);
    output_leaf_recursive(T->left);
    output_leaf_recursive( T->right); 
  }
}

void output_leaf_norecursive(BTREE T){
                                                                              
  STACK S = creat_stack();
  while((T != NULL)||(!is_stack_empty(S))){                                   
    if(T != NULL){ 
     if((T->left == NULL)&&(T->right == NULL))                                      visit(T->element);                                                      
      push(T, S);
      T = T->left;
    }
    else{                                                                     
      T = top_stack(S);
      T = T->right;                                                           
      pop(S);
    }                                                                         
 }
  
  free_stack(S);                                                              
}             

void exchange_recursive(BTREE T){

  TREE_NODE tmp;

  if(T != NULL){
    exchange_recursive(T->left);
    exchange_recursive(T->right); 
    tmp = T->left;
    T->left = T->right;
    T->right = tmp;
  }   
   
}

void exchange_norecursive(BTREE T){

  STACK S = creat_stack();
  TREE_NODE tmp;
                                                    
  while((T != NULL)||(!is_stack_empty(S))){                                   
    if(T != NULL){
      push(T, S);
      tmp = T->left;
      T->left = T->right;
      T->right = tmp;
      T = T->left;                                                            
    }                                                                         
    else{
      T = top_stack(S);
      T = T->right;
      pop(S);
    }                                                                         
 }                                                                            
  
  free_stack(S);           
}



















