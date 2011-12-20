#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct list_node *node_ptr;
typedef int element_type;

struct list_node{

  element_type adjvex;
  node_ptr next;
};

struct queue_record{

  unsigned int q_max_size;
  unsigned int q_rear;
  unsigned int q_front;
  unsigned int q_size;
  element_type *q_array;
};

typedef node_ptr LIST;
typedef node_ptr position;
typedef struct queue_record *QUEUE;

struct adj_list{

  unsigned int list_size;
  LIST *the_lists;
};

typedef struct adj_list *GRAPH;

GRAPH creat_graph(unsigned int list_size);
void free_graph(GRAPH G);
GRAPH init_graph(GRAPH, int g[][7], int row, int col);
void adj_insert(element_type adj, GRAPH G, int row, int col);
void bfs(GRAPH G, element_type adj);
int is_queue_empty(QUEUE Q);
void make_queue_null(QUEUE Q);
unsigned int succ(unsigned int value, QUEUE Q);
void enqueue(element_type x, QUEUE Q);
int is_queue_full(QUEUE Q);
element_type dequeue(QUEUE Q);

int main(int argc, char *argv[]){
  
  int i;
  int g[7][7] = {{0,1,0,1,0,0,0},
                 {0,0,0,1,1,0,0},
                 {1,0,0,0,0,1,0},
                 {0,0,1,0,1,1,1},
                 {0,0,0,0,0,0,1},
                 {0,0,0,0,0,0,0},
                 {0,0,0,0,0,1,0}};

  GRAPH G = creat_graph(7);
  G = init_graph(G, g, 7, 7);

/*  for(i=0; i<7; i++){
    while(G->the_lists[i]->next != NULL){
      printf("%d ", G->the_lists[i]->next->adjvex);
      G->the_lists[i] = G->the_lists[i]->next;
    }
    printf("\n");
  }*/

  bfs(G,2);
  free(G);
  return 0;

}

GRAPH creat_graph(unsigned int list_size){

  GRAPH G;
  int i;
  
  /* allocate graph structure*/
  G = (GRAPH)malloc(sizeof(struct adj_list));
  if(G == NULL){
    printf("malloc graph structure error\n");
    exit(1);
  }
  
  G->list_size = list_size;
  
  /*allocate the array of point */
  G->the_lists = (position *)malloc(sizeof(LIST) * G->list_size);
  if(G->the_lists == NULL){
    printf("malloc the lists error\n");
    exit(1);
  }
 
  /* allocate the list headers*/ 
  for(i=0; i<G->list_size; i++){
    G->the_lists[i] = (LIST)malloc(sizeof(struct list_node));
    if(G->the_lists[i] == NULL){
      printf("malloc list error\n");
      exit(1);
    }
    else
      G->the_lists[i]->next = NULL;
  }

  return G;
}

void free_graph(GRAPH G){

  int i;
  position tmp, cell;

  for(i=0; i<G->list_size; i++){
    while(G->the_lists[i]->next != NULL){
      cell = G->the_lists[i];
      G->the_lists[i] = G->the_lists[i]->next;
      free(cell);
    }
  }
  free(G->the_lists);
  free(G);  
}

GRAPH init_graph(GRAPH G, int g[][7], int row, int col){

  int i, j;
  
  for(i=0; i<row; i++){
    for(j=0; j<col; j++)
       adj_insert(g[i][j], G, i, j);
  }
  return G;
}

void adj_insert(element_type adj, GRAPH G, int row, int col){

  position new_cell;
  LIST L;

  new_cell = (position)malloc(sizeof(struct list_node));
  if(new_cell == 0){
    printf("insert new cell error\n");
    exit(1);
  }
  else{
    if(adj != 0){
      L = G->the_lists[row];
      new_cell->next = L->next;
      new_cell->adjvex = col;
      L->next = new_cell;
    }
  }
}

void bfs(GRAPH G, element_type adj){
  
  QUEUE Q;
  int color[G->list_size];
  int dist[G->list_size];
  int i;
  element_type tmp;


  for(i=0; i<G->list_size; i++){
    color[i] = 0;
    dist[i] = MAX;
  }

  Q = (QUEUE)malloc(sizeof(struct queue_record));
  if(Q == NULL){
    printf("malloc Q error\n");
    exit(1);
  }
 
  Q->q_array = malloc(sizeof(element_type) * G->list_size);
  if(Q->q_array == NULL){
    printf("malloc Q->array error\n");
    exit(1);
  }
 
  Q->q_max_size = G->list_size;
  make_queue_null(Q);

  enqueue(adj, Q);
  dist[adj] = 0;

  while(!is_queue_empty(Q)){
    tmp = dequeue(Q);
    if(color[tmp] == 0){
      color[tmp] = 1;
    while(G->the_lists[tmp]->next != NULL){
      enqueue(G->the_lists[tmp]->next->adjvex, Q);
      if(color[G->the_lists[tmp]->next->adjvex] == 0)
      dist[G->the_lists[tmp]->next->adjvex] = dist[tmp]+1;
      G->the_lists[tmp] = G->the_lists[tmp]->next;
    }
    color[tmp] = 2;}
  }

  for(i=0; i<G->list_size; i++)
    printf("%d ", dist[i]); 
  printf("\n"); 
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
    value == 0;
  
  return value;
}

void enqueue(element_type x, QUEUE Q){

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

element_type dequeue(QUEUE Q){

  element_type tmp;
  
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
