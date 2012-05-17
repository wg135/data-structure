#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int lookup[MAX];

int fibb_recusive(int n);
int fibb_top(int n);
int fibb_down(int n);
void fibb_init();

int main(int argc, char *argv[]){

  printf("fibb of 6 is %d\n", fibb_recusive(6));
  fibb_init();
  printf("fibb of 6 is %d\n", fibb_top(6));
  printf("fibb of 6 is %d\n", fibb_down(6));

  return 0;
}

int fibb_recusive(int n){

  if(n <= 1)
    return n;

  return fibb_recusive(n-1) + fibb_recusive(n-2);
}

int fibb_top(int n){

  if(lookup[n] == -1){
    if(n > 1)
      lookup[n] = fibb_top(n-1) + fibb_top(n-2);
    else
      lookup[n] = n;
}  
  return lookup[n];
}

void fibb_init(){

  int i;
  for(i=0; i<MAX; i++)
    lookup[i] = -1;
}

int fibb_down(int n){

  int f[n+1];
  int i;
  
  f[0] = 0;
  f[1] = 1;
  
  for(i=2; i<=n; i++)
     f[i] = f[i-1] + f[i-2];
 
  return f[n]; 
}
