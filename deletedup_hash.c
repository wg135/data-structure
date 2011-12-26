#include <stdio.h>
#include <stdlib.h>

#define random(x) (rand()%x)

typedef struct node *node_ptr;
typedef int element_type;
typedef unsigned int INDEX;

struct node{

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

int is_list_empty(LIST L);
position init_list();
void insert(element_type x, LIST L);
void print_list(LIST L);
void delet_list(LIST L);
void delet_dup(LIST L);
void delet_dup_hash(LIST L);
HASH_TABLE init_table(unsigned int table_size);
position hash_find(element_type key, HASH_TABLE H);
INDEX hash(element_type key, unsigned int H_SIZE);
void hash_insert(element_type key, HASH_TABLE H);
void delete_hashtable(HASH_TABLE H);

int main(int argc, char *argv[]){

  LIST L;
  int i;

  L = init_list();
  for(i=0; i<20; i++)
    insert(random(30), L);

  print_list(L);
  
  delet_dup_hash(L);
  //delet_dup(L);
  print_list(L);
  delet_list(L);
  
  return 0;  
}

int is_list_empty(LIST L){

  return (L->next == NULL);
}

position init_list(){

  LIST L = (position)malloc(sizeof(struct node));
  if(L == NULL){
    printf("init list error\n");
    exit(1);
  }
  
  L->next = NULL;

  return L;
}

void insert(element_type x, LIST L){

  position tmp_cell;

  tmp_cell = (position)malloc(sizeof(struct node));
  if(tmp_cell == NULL){
    printf("insert malloc error\n");
    exit(1);
  }
  else{
    tmp_cell->element = x;
    tmp_cell->next = L->next;
    L->next = tmp_cell;
  }
  
}

void print_list(LIST L){

  position l;
  int i;

  for(l = L->next; l != NULL; l = l->next)
    printf("%d ", l->element);

  printf("\n");
}

void delet_list(LIST L){

  position tmp, p;
  
  p = L->next;
  L->next = NULL;
  while(p != NULL){
    tmp = p->next;
    free(p);
    p = tmp;
  }

  free(L);  
}

void delet_dup(LIST L){

  position tmp, l, cell, pre;
  
  tmp = L->next;
  while(tmp != NULL){
    l = tmp->next;
    pre = tmp;
    while(l != NULL){
      if(tmp->element == l->element){
         cell = l;
         pre->next = l->next;
         free(cell);
         l = l->next; 
      }
      else{
        l = l->next;
        pre = pre->next;
      }
    }
    tmp = tmp->next;
   
  } 
}

HASH_TABLE init_table(unsigned int table_size){

  HASH_TABLE H;
  int i;

  H = (HASH_TABLE)malloc(sizeof(struct hash_table));
  if(H == NULL){
    printf("init hash table error\n");
    exit(1);
  }
  
  H->table_size = table_size;
  
  /* allocate list points*/
  H->the_lists = (position *)malloc(sizeof(LIST) * H->table_size);
  if(H->the_lists == NULL){
    printf("the list points malloc error\n");
    exit(1);
  }
   
  /* allocate list headers */
  for(i=0; i<H->table_size; i++){
    H->the_lists[i] = (LIST)malloc(sizeof(struct node));
    if(H->the_lists[i] == NULL){
      printf("list header malloc error\n");
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
  
  while((p != NULL) && (p->element != key))
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
    new_cell = (position)malloc(sizeof(struct node));
    if(new_cell == NULL){
      printf("insert malloc error\n");
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

void delet_dup_hash(LIST L){

  HASH_TABLE H;
  position pre, l, tmp;

  H = init_table(17);
  l = L->next;
  pre = L;
  while(l != NULL){
    if(hash_find(l->element, H) == NULL){
      hash_insert(l->element, H);
      l = l->next;
      pre = pre->next;
    }
    else{
      tmp = l;
      pre->next = l->next;
      free(tmp);
      l = l->next;
    }
  }

  free(H);  
}

void delete_hashtable(HASH_TABLE H){

  int i;
  position tmp_cell;
  
  for(i=0; i<H->table_size; i++){
    while(H->the_lists[i]->next != NULL){
      tmp_cell = H->the_lists[i]->next;
      H->the_lists[i]->next = H->the_lists[i]->next->next;
      free(tmp_cell); 
    }
    free(H->the_lists[i]);
  }
  
  free(H->the_lists);
  free(H);
}
