#include "singlelink.h"

LIST delete_dup(LIST L);

int main(int argc, char *argv[]){
  
  LIST L = NULL;
  position tmp;
  int i; 
  int array[6] = {0, 1, 1, 1, 2, 3}; 
  L = insert(0, NULL);
  tmp = L;

  for(i=1; i<6; i++){
    tmp = insert(array[i], tmp);
  }
 
  L = delete_dup(L); 
  print_single_list(L->next);

  return 0; 
}

LIST delete_dup(LIST L){

  position p_cur = L->next, p_nxt, p_pre;
  position tmp = NULL;
  int key = 0;
 
  p_pre = L; 
  if(L == NULL)
    return NULL; 

  p_nxt = p_cur->next;
  key = p_cur->element;
  while(p_nxt != NULL){
    while((p_nxt != NULL)&&(p_cur->element == p_nxt->element)){
      tmp = p_nxt;    //delete next->element
      p_nxt = p_nxt->next;
      p_cur->next = p_nxt;
      free(tmp);
      key = 1;  
     } 
     if(key == 1){  //delete curr->element
      tmp = p_cur;
      p_cur = p_cur->next;
      p_nxt = p_cur->next;
      p_pre->next = p_cur;
      free(tmp);
      key = 0; 
     }
     else{ //move on
       p_pre = p_pre->next;
       p_cur = p_cur->next;
       p_nxt = p_nxt->next; 
     }
  } 

  return L;  

}


