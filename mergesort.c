#include <stdio.h>
#include <stdlib.h>
#define random(x) (rand()%x)
#define min(A, B) (A < B)? A: B

void merge_sort(int test[], int tmp[], int l, int r);
void merge_sort2(int test[], int tmp[], int l, int r);
void merge(int c[], int d[], int l, int m, int n);

int main(int argc, char *argv[]){

  int test_array[20];
  int i; 
  int c[20];
  
  for(i=0; i<20; i++){
    test_array[i] = random(100);
    printf("%d ", test_array[i]);
  }
  printf("\n");
  
  merge_sort2(test_array, c, 0, 19);

  for(i=0; i<20; i++)
    printf("%d ", test_array[i]);
  printf("\n");

  return 0;
}

void merge_sort(int test[], int tmp[], int l, int r){

  int m = (r+l)/2;
  if(r <= l)
    return;
  merge_sort(test, tmp, l, m);
  merge_sort(test, tmp, m+1, r);
  merge(test, tmp, l, m, r);
}

void merge(int c[], int d[], int l, int m, int n){

  int i, j, k;

  for(i=m+1; i>l; i--)
    d[i-1] = c[i-1];
  for(j=m; j<n; j++)
    d[n+m-j] = c[j+1];

   for(k=l; k<=n; k++){
    if(d[i] < d[j])
      c[k] = d[i++];
    else
      c[k] = d[j--];
   }
/*   for(k=l; k<=n; k++){
    printf("%d ", d[k]);
  } 
  printf("\n");*/
}

void merge_sort2(int test[], int tmp[], int l, int r){
  
  int i, m;
  for(m=1; m<r-1; m = m+m)
    for(i=l; i<r-m; i+= m+m)
    merge(test,tmp, i, i+m-1, min(i+m+m-1 ,r));   
}






