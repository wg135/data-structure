#include <stdio.h>
#include <stdlib.h>

int dp_coin(int value[], int num, int money);

int main(int argc, char *argv[]){

  int value[3] = {1, 4, 5};
  int money = 8;
  
  printf("%d needs %d coins\n", money, dp_coin(value, sizeof(value)/sizeof(value[0]), money));
  return 0;
}

int dp_coin(int value[], int num, int money){
  
  int i, j;
  int s[money+1];
  int tmp, minicoin;
 
  for(i=0; i<=money; i++)
    s[i] = 0;
 
  for(i=1; i<=money; i++){
    minicoin = i;
    for(j=0; j<num; j++){
      if(value[j] <= i){
        tmp = s[i-value[j]]+1;
      if(tmp < minicoin)
        minicoin = tmp;
      }
    }
    s[i] = minicoin;
  }  
  return s[money];
}
