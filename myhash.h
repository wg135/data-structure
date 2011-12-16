#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list_node *node_ptr;
typedef int element_type;
typedef unsigned int INDEX;

struct list_node{

  element_type element;
  node_ptr next;
};

typedef node_ptr LIST;
typedef node_ptr position;

struct hash_table{

  unsigned int table_size;
  LIST *the_lists;
};

typedef struct hash_table *HASH_TABLE;


HASH_TABLE init_table(unsigned int table_size);
position hash_find(element_type key, HASH_TABLE H);
INDEX hash(element_type key, unsigned int H_SIZE);
void hash_insert(element_type key, HASH_TABLE H);


HASH_TABLE init_table(unsigned int table_size){

  HASH_TABLE H;
  int i;

  H = (HASH_TABLE)malloc(sizeof(struct hash_table));
  if(H == NULL){
    printf("malloc H failed\n");
    exit(1);
  }
  
  H->table_size = table_size;
  
  H->the_lists = (position *)malloc(sizeof(LIST) * H->table_size);
  if(H->the_lists == NULL){
    printf("malloc the list failed\n");
    exit(1);
  }

  for(i=0; i<H->table_size; i++){
    H->the_lists[i] = (LIST)malloc(sizeof(struct list_node));
    if(H->the_lists[i] == NULL){
      printf("list failed\n");
      exit(1);
    } 
    else
      H->the_lists[i]->next = NULL; 
  }

  return H; 
}

position hash_find(element_type key, HASH_TABLE H){

  position p;
  LIST L;

  L = H->the_lists[hash(key, H->table_size)];
  p = L->next;
  
  while((p != NULL)&&(p->element != key))
    p = p->next;

  return p;
}

INDEX hash(element_type key, unsigned int H_SIZE){

  return key % H_SIZE;
}

void hash_insert(element_type key, HASH_TABLE H){

  position pos, new_cell;
  LIST L;

  pos = hash_find(key, H);
  if(pos == NULL){
    new_cell = (position)malloc(sizeof(struct list_node));
    if(new_cell == NULL){
      printf("out of space\n");
      exit(1);
    }
  else{
    L = H->the_lists[hash(key, H->table_size)];
    new_cell->next = L->next;
    new_cell->element = key;
    L->next = new_cell;
  }
  }
}
