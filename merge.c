#include <stdio.h>
#define random(x) (rand()%x)

void merge1(int c[], int a[], int b[], int m, int n);
void merge2(int c[], int l, int m, int n);

int main(int argc, char *argv[]){

  int i;
  int a[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
  int b[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
  int c[20];

 // merge1(c, a, b, 10, 10);
  for(i=0; i<10; i++)
    c[i] = a[i];
  for(i=10; i<20; i++)
    c[i] = b[i-10];
  
  for(i=0; i<20; i++)
    printf("%d ", c[i]);
  printf("\n");

  merge2(c, 0, 10, 20);
  
  for(i=0; i<20; i++)
    printf("%d ", c[i]);
  printf("\n");



  return 0;
  
}

//using sentinel
void merge1(int c[], int a[], int b[], int m, int n){

  int i=0, j=0, k;
  
  for(k=0; k<m+n; k++){
    if(i == m){
      c[k] = b[j++];
      continue;
    }
    if(j == n){
      c[k] = a[i++];
      continue;
    }
    if(a[i] < b[j])
      c[k] = a[i++];
    else
      c[k] = b[j++];
  }  
}

//not using sentinel
void merge2(int c[], int l, int m, int n){

  int d[n-l];
  int i, j, k;

  for(i=m; i>l; i--)
    d[i-1] = c[i-1];
  for(j=m; j<n; j++)
    d[j] = c[n-1-j+m];
   i= l;
   j = n-1; 
  for(k=l; k<n; k++){
    if(d[i] < d[j])
     c[k] = d[i++];
    else
      c[k] = d[j--];
  }  
}


