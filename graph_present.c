#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list_node *node_ptr;
typedef int element_type;

struct list_node{

  element_type adjvex;
  node_ptr next;
};

typedef node_ptr LIST;
typedef node_ptr position;

struct adj_list{

  unsigned int list_size;
  LIST *the_lists;
};

typedef struct adj_list *GRAPH;

GRAPH creat_graph(unsigned int list_size);
void free_graph(GRAPH G);
GRAPH init_graph(GRAPH G, int g[][7], int row, int col);
void adj_insert(element_type adj, GRAPH G, int row, int col);

GRAPH creat_graph(unsigned int list_size){

  GRAPH G;
  int i;

  /* allocate graph structure */
  G = (GRAPH)malloc(sizeof(struct adj_list));
  if(G == NULL){
    printf("malloc error\n");
    exit(1);
  }
  
  G->list_size = list_size;

  /* allocate the array of point */
  G->the_lists = (position *)malloc(sizeof(LIST) * G->list_size);
  if(G->the_lists == NULL){
    printf("malloc the lists error\n");
    exit(1);
  }
  
  /* allocate the headers */
  for(i=0; i<G->list_size; i++){
    G->the_lists[i] = (LIST)malloc(sizeof(struct list_node));
    if(G->the_lists[i] == NULL){
      printf("list failed\n");
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
    tmp = G->the_lists[i];
    while(tmp->next != NULL){
      cell = tmp;
      tmp = tmp->next;
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
    printf("out of space\n");
    exit(1);
  }
  else{
    if(adj != 0){
      L = G->the_lists[row];
      new_cell->next = L->next;
      new_cell->adjvex = col+1;
      L->next = new_cell;  
    }
  }
}

int main(int argc, char *argv[]){

  int i;

  int g[7][7] = {{0,1,1,1,0,0,0}, 
                 {0,0,0,1,1,0,0},
                 {0,0,0,0,0,1,0},
                 {0,0,1,0,0,1,1},
                 {0,0,0,1,0,0,0},
                 {0,0,0,0,0,0,0},
                 {0,0,0,0,0,1,0}};;

  GRAPH G = creat_graph(7);
  G = init_graph(G, g, 7, 7);
 
  for(i=0; i<7; i++){
    while(G->the_lists[i]->next != NULL){
      printf("%d ", G->the_lists[i]->next->adjvex); 
      G->the_lists[i] = G->the_lists[i]->next;  
    }
    printf("\n");
  }
  

  free(G);
  return 0;
}
