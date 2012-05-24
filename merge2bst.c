/* merge two binary search tree*/

#include "binarytree.h"

BTREE mergetree(BTREE T1, BTREE T2, int len1, int len2);
void inorder_array(BTREE T, int array[], int *cnt);
void sort2array(int array[], int array1[], int array2[], int len1, int len2);
BTREE array2tree(int array[], int start, int end);

int main(int argc, char *argv[]){

  BTREE T1 = NULL, T2 = NULL, T = NULL;
  
  /* creat T1 */
  T1 = new_node(100);
  T1->left = new_node(50);
  T1->right = new_node(300);
  T1->left->left = new_node(20);
  T1->left->right = new_node(70);

  /* creat T2 */
  T2 = new_node(80);
  T2->left = new_node(40);
  T2->right = new_node(120);

  T = mergetree(T1, T2, 5, 3);
  inorder(T);
  printf("\n");

  return 0;
}

/* merge two trees: T1 T2*/
BTREE mergetree(BTREE T1, BTREE T2, int len1, int len2){

  int array1[len1], array2[len2];
  int array[len1+len2];
  BTREE T = NULL;
  int i;
  int m = 0, n = 0; 
  
  inorder_array(T1, array1, &m);
  inorder_array(T2, array2, &n);
  sort2array(array, array1, array2, len1,len2);
  T = array2tree(array, 0, len1+len2-1); 
 
  return T;
}

/* covert tree to sorted array*/
void inorder_array(BTREE T, int array[], int *cnt){

  TREE_NODE tmp = T;
 
  if(tmp == NULL)
    return;
 
  if(tmp != NULL){
    inorder_array(T->left, array, cnt);
    array[*cnt] = T->element;
    (*cnt)++;
    inorder_array(T->right, array,cnt);
  }
}

/* sort 2 sored array*/
void sort2array(int array[], int array1[], int array2[], int len1, int len2){

  int m = 0, n =0, i=0;

  while((m<len1)&&(n<len2)){
    if(array1[m]<=array2[n])
      array[i++] = array1[m++];
    else
      array[i++] = array2[n++];
  }
  if(m == len1){
    while(n<len2)
      array[i++] = array2[n++];
  }
  if(n == len2){
    while(m<len1)
      array[i++] = array1[m++];
  }
}

/* covert inorder array to tree*/
BTREE array2tree(int array[], int start, int end){
  
  int i;
  BTREE T = NULL;
 
  if(array == NULL)
    return NULL;
  if(start > end)
    return NULL;
  i = (start + end)/2;    
  T = new_node(array[i]);
  T->left = array2tree(array, start, i-1);
  T->right = array2tree(array, i+1, end);  
  
  return T;
}
