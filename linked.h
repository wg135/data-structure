typedef struct node *node_ptr;
typedef int elementype;

struct node{

  elementype element;
  node_ptr next;
};

typedef node_ptr LIST;
typedef node_ptr postion;
postion find_previous(elementype x, LIST L);
void insert(elementype x, LIST L, int num);
void print_list(LIST P, LIST L);
LIST union_list(LIST L, LIST P);
LIST intersection(LIST F, LIST L, LIST P);
LIST reversal_list(LIST L);
postion init_list();

LIST reversal_list(LIST L){

  postion t;
  postion y = L->next;
  LIST r = NULL;
  
  while(y != NULL){
    t = y->next;
    y->next = r;
    r = y;
    y = t;
  }

  return r;

}
/* fuction to test whether a linked list is empty*/
int is_empty(LIST L){

  return(L->next == NULL);
}

/*fuction to test whether current position is last in a linked list*/
int is_last(postion p, LIST L){

  return(p->next == NULL);
}

LIST intersection(LIST F, LIST L, LIST P){
  int i, j =0;
  postion l, start, tmp;
  
  l = L->next;
  start = P->next;
  tmp = F;
  while(start != NULL){
  if(l->element == start->element){
    tmp->next = start;
    tmp = tmp->next;
    start = start->next;
    l = l->next;
  }
  else{
    l = l->next;
    if(l == NULL){
      l = L->next;
      start = start->next;
   }
    
  }
  
}
  return F;
}

LIST union_list( LIST P, LIST L){
 
  int i, j=0;
  postion l, start;
  
  l = L->next;
  start = P->next;

  while(l != NULL){
    if(l->element < start->element){
      start = start->next;
      insert(l->element, P, j);
      l = l->next;
      j += 2;}
    else{
      start = start->next;
    }
  }
  
  return P;   
  } 
   
/* init linked list*/
postion init_list(){
 
  LIST L;
  
  L = (postion)malloc(sizeof(struct node));
  if(L == NULL)
    printf("init failed\n");
  L->next = NULL;

  return L;
}
/* return position of x in L, NULL if not found*/
postion find(elementype x, LIST L){

  postion p;

  p =  L->next;
  while((p != NULL)&&(p->element != x))
    p= p->next;

  return p;
}

/* delete from a list*/
void my_delete(elementype x, LIST L){

  postion p, tmp_cell;
  
  p = find_previous(x, L);
  if(p->next != NULL){
    tmp_cell = p->next;
    p->next = tmp_cell->next;
    free(tmp_cell);
  }
}

/* If element is not found, then next field of returned value is NULL*/
postion find_previous(elementype x, LIST L){

  postion p;
  p = L;
  while((p->next != NULL)&&(p->next->element != x))
   p = p->next;

  return p;
}

/* insert after legal position p*/
void insert(elementype x, LIST L, int num){

  postion tmp_cell, p;
  int i;
  p = L;
  tmp_cell = (postion)malloc(sizeof(struct node));
  if(tmp_cell == NULL){
    printf("out of space\n");
    exit(1);
  }
  else{
    tmp_cell->element = x;
    for(i=0; i<num; i++)
      p = p->next;
    tmp_cell->next = p->next;
    p->next = tmp_cell;
  }
  
}

/* delet the list*/
void delet_list(LIST L){

  postion p, tmp;
  
  p = L->next;
  L->next = NULL;
  while(p != NULL){
    tmp = p->next;
    free(p);
    p = tmp;
  }
}

/* implement ex 3.2 print list fucntion*/
void print_list(LIST P, LIST L){
  
  postion l, p;
  int i;
  for(l = L->next; l != NULL; l = l->next){
    p = P;
   for(i=l->element; i>0;i--){
      p = p->next;
   }
   printf("%d\t", p->element);
}
  printf("\n");
}










