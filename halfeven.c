#include <stdio.h>
#include <stdlib.h>

#define random(x) (rand()%x)

void half_even(int a[], int num);
int iseven(int a);

int main(int argc, char *argv[]){
 
  int i;
  int a[20];

  for(i=0; i<20; i++){
    a[i] = random(100);
    printf("%d ", a[i]);
  }
  printf("\n");

  half_even(a, sizeof(a)/sizeof(a[0]));
  for(i=0; i<20; i++)
    printf("%d ", a[i]);
 
  printf("\n");

  return 0;
 
}


void half_even(int a[], int num){

  int left = 0;
  int right = num - 1;
  int tmp;

  if((a == NULL)||(num == 0)){
    printf("empty array\n");
    exit(1);
  }
  
  while(left < right){
    if(iseven(a[left])&&(!iseven(a[right]))){
      tmp = a[left];
      a[left] = a[right];
      a[right] = tmp;
    }
    if(!iseven(a[left]))
      left++;
    if(iseven(a[right]))
      right--;
  }
 
}


int iseven(int a){

  return ((a & 0x00000001) == 0);
}
