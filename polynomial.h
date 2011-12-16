typedef struct node *node_ptr;
typedef int elementype;


struct node{

  elementype coefficient;
  elementype exponent;
  node_ptr next;
};

typedef node_ptr LIST;
typedef node_ptr position;
position find(elementype x, LIST L);

position find(elementype x, LIST L){
 
  position p;
  
  p = L;
  while((p->next != NULL)&&(p->next->exponent <= x))
    p = p->next;

  return p;
}

position init_list(){

  LIST L;
 
  L = (position)malloc(sizeof(struct node));
  if(L == NULL)
    printf("init failed\n");
  
  L->next = NULL;

  return L;
}
LIST poly_mulx2(LIST final, LIST poly1, LIST poly2){

}


LIST poly_mulx1(LIST final, LIST poly1, LIST poly2){

  position poly_tmp1, poly_tmp2, final_tmp, final_index, tmp;

  poly_tmp1 = poly1->next;
  poly_tmp2 = poly2->next;

  final_tmp = final;
  while(poly_tmp1 != NULL){
    while(poly_tmp2 != NULL){
    tmp = (position)malloc(sizeof(struct node));
    if(tmp == NULL){
      printf("malloc unit failed\n");
      exit(1);
    }
 
    tmp->exponent = poly_tmp1->exponent + poly_tmp2->exponent;
    tmp->coefficient = poly_tmp1->coefficient * poly_tmp2->coefficient;
    final_index = final;
    final_index = find(tmp->exponent, final);
    if(final_index == NULL){
      final_tmp->next = tmp;
      final_tmp = final_tmp->next;
    }
    else if(final_index->exponent == tmp->exponent){
    final_index->coefficient += tmp->coefficient;
   }
    else{
      tmp->next = final_index->next;
      final_index->next = tmp;
    }
 
   poly_tmp2 = poly_tmp2->next;
}
  poly_tmp2 = poly2->next;
  poly_tmp1 = poly_tmp1->next;
  }

  return final;

}


LIST poly_add(LIST final, LIST poly1, LIST poly2){

  position poly_tmp1, poly_tmp2, final_tmp;
  
  poly_tmp1 = poly1->next;
  poly_tmp2 = poly2->next;
  final_tmp = final;
  
  while((poly_tmp1 != NULL)&&(poly_tmp2 != NULL)){
    if(poly_tmp1->exponent == poly_tmp2->exponent){
      poly_tmp1->coefficient += poly_tmp2->coefficient;
      final_tmp->next = poly_tmp1;
      final_tmp = final_tmp->next;
      poly_tmp1 = poly_tmp1->next;
      poly_tmp2 = poly_tmp2->next;
    }
    else if(poly_tmp1->exponent < poly_tmp2->exponent){
       final_tmp->next = poly_tmp1;
       final_tmp = final_tmp->next;
       poly_tmp1 = poly_tmp1->next;
    }
    else{
      final_tmp->next = poly_tmp2;
      final_tmp = final_tmp->next;
      poly_tmp2 = poly_tmp2->next;
    }
  }
 
  while(poly_tmp1 != NULL){
    final_tmp->next = poly_tmp1;
    final_tmp = final_tmp->next;
    poly_tmp1 = poly_tmp1->next;
  }
 
  while(poly_tmp2 != NULL){
    final_tmp->next = poly_tmp2;
    final_tmp = final_tmp->next;
    poly_tmp2 = poly_tmp2->next;
  }
  return final;
}
