#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int INDEX;
typedef int element_type;

enum kind_of_entry {legitimate, empty, deleted};

struct hash_entry{

  element_type element;
  enum kind_of_entry info;
};

typedef INDEX position;
typedef struct hash_entry *entry;
typedef struct hash_entry cell1;
typedef entry cell;

struct hash_table {

  unsigned int table_size;
  cell the_cells;
};

typedef struct hash_table *HASH_TABLE;

HASH_TABLE init_table(unsigned int table_size);
position find(element_type key, HASH_TABLE H);
INDEX hash(element_type key, unsigned int H_SIZE);
void insert(element_type key, HASH_TABLE H);
HASH_TABLE rehash(HASH_TABLE H);

HASH_TABLE init_table(unsigned int table_size){

  HASH_TABLE H;
  int i;

  H = (HASH_TABLE)malloc(sizeof(struct hash_table));
  if(H == NULL){
    printf("init H failed\n");
    exit(1);
  }
  
  H->table_size = table_size;
  H->the_cells = (cell)malloc(sizeof(cell) * H->table_size);
  if(H->the_cells == NULL){
    printf("out of space\n");
    exit(1);
  }

  for(i=0; i<H->table_size; i++)
    H->the_cells[i].info = empty;

  return H;
}

position find(element_type key, HASH_TABLE H){

  position i, current_pos;

  i = 0;
  current_pos = hash(key, H->table_size);
  while((H->the_cells[current_pos].element != key) && (H->the_cells[current_pos].info != empty)){
    current_pos += 2*(++i) - 1;

  if(current_pos >= H->table_size)
    current_pos -= H->table_size;
  }

  return current_pos;
}

INDEX hash(element_type key, unsigned int H_SIZE){

  return key % H_SIZE;
}

void insert(element_type key, HASH_TABLE H){

  position pos;
  
  pos = find(key, H);
  if(H->the_cells[pos].info != legitimate){
    H->the_cells[pos].info = legitimate;
    H->the_cells[pos].element = key;
  }
}

/*HASH_TABLE rehash(HASH_TABLE H){

  unsigned int i, old_size;
  cell1 *old_cells;

  old_size = H->table_size;
  old_cells = H->the_cells;

  HASH_TABLE H1 = (HASH_TABLE)malloc(sizeof(struct hash_table));
  for(i=0; i<old_size; i++)
    if(old_cells[i].info == legitimate)
      insert(old_cells[i].element, H1);

  free(old_cells); 
*/
/*  return H1;
}

*/

