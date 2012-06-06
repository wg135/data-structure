#include <stdio.h>
#include <limits.h>

int egg_floor(int egg, int floor);
int egg_dp(int egg, int floor);
int Max(int a, int b);

int main(int argc, char *argv[]){

  int egg = 2;
  int floor = 10;

  printf("%d egg and %d floor need %d times\n", egg, floor, egg_floor(egg, floor));
printf("%d egg and %d floor need %d times\n", egg, floor, egg_dp(egg, floor));
  return 0;  
}

int egg_floor(int egg, int floor){

  int number = INT_MAX;
  int i, tmp;
  if((floor == 0)||(floor == 1))
    return floor;

  if(egg == 1)
    return floor;
  
  for(i = 1; i<=floor; i++){
    tmp = Max(egg_floor(egg-1, i-1), egg_floor(egg, floor-i));
    if(tmp < number)
      number = tmp;
  }
  return number + 1;
}

int egg_dp(int egg, int floor){

  int result[egg+1][floor+1];
  int i, j, k;
  int tmp;
  for(i=1; i<= egg; i++){
    result[i][0] = 0;
    result[i][1] = 1;
  }

  for(j=1; j<=floor; j++)
    result[1][j] = j;
 
  for(i=2; i<=egg; i++){
    for(j=2; j<=floor; j++){
      result[i][j] = INT_MAX;
      for(k=1; k<=floor; k++){
	tmp = 1 +  Max(result[i-1][k-1], result[i][j-k]);
        if(tmp < result[i][j])
          result[i][j] = tmp;
      }
    }
  } 
  return result[egg][floor];
}

int Max(int a, int b){
  return(a>b)? a: b;
}
