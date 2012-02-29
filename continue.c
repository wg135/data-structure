#include <stdio.h>
#include <stdlib.h>

void findcontinue(int n);
void printnumber(int left, int right);

int main(int argc, char *argv[]){

  findcontinue(15);
  return 0;
  
}

void findcontinue(int n){
 
  int left, right;
  int middle;
  int sum;

  left = 1;
  right = 2;
  middle = (n+1)/2;
  sum = left + right;
 
  if(n < 3)
    return;
  
  while(left < middle){
    if(sum == n){
      printnumber(left, right);
    }
    while(sum > n){
      sum -= left;
      left++;
      if(sum == n)
        printnumber(left, right);
    }
    
    right++;
    sum += right; 
    }
  }
    
  
  
void printnumber(int left, int right){

  int i;

  for(i=left; i<=right; i++)
    printf("%d ", i); 

  printf("\n"); 
}
