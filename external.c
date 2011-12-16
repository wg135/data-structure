#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define random(x) (rand()%x)

static unsigned int BUF_PAGES;   /* pages in buff */
static unsigned int PAGE_SIZE;   /* page size */
static unsigned int BUF_SIZE;    /* buff size = page size * pages in buff */
static unsigned int K;           /* K mulit way*/

void quick_sort(int test[], int num);
void q_sort(int test[], int left, int right);
int partition(int test[], int left, int right);
int select_pivot(int test[], int left, int right);
void swap(int *a, int *b);
void usage();

int main(int argc, char *argv[]){

  char file_name[100];
  FILE *fd;

  if(argc != 3){
    usage();
    return 0;
  }
  
  strcpy(file_name, argv[1]);
  fd = fopen(file_name, "r");
  if(fd == NULL){
    printf("open file error\n");
    exit(1);
  }

}

void quick_sort(int test[], int num){

  q_sort(test, 0, num-1);
}

void q_sort(int test[], int left, int right){

  int pi;

  if(left >= right)
    return;

  pi = partition(test, left, right);
  q_sort(test, left, pi-1);
  q_sort(test, pi+1, right); 
}

int partition(int test[], int left, int right){

  int p, store;
  int i;

  p = select_pivot(test, left, right);
  swap(&test[p], &test[right]);
  store = left;

  for(i=left; i<right; i++){
    if(test[i] <= test[right]){
      swap(&test[i], &test[store]);
      store++;
    }   
  } 
  swap(&test[store], &test[right]);
  return store;
}

int select_pivot(int test[], int left, int right){

  int center;

  center = (left + right)/2;
  if(test[left] > test[center])
    swap(&left, &center);
  if(test[left] > test[right])
    swap(&left, &right);
  if(test[center] > test[right])
    swap(&center, &right);

  return center;
}

void swap(int *a, int *b){

  int tmp;
  
  tmp = *a;
  *a = *b;
  *b = tmp;
}

void usage(){

  printf("usage: ./external <filename> <K>\n");
  printf("filename: need sort\n");
  printf("K: K ways merge\n");
  exit(1); 
}


