#include <stdio.h>
#include <stdlib.h>

int numberofsolutio1(unsigned int num);
int numberofsolutio2(unsigned int num);

int number1(unsigned int num);

int main(int argc, char *argv[]){

  printf("from 1 to 12 has total 1: %d\n", numberofsolutio1(12));
  printf("from 1 to 12 has total 1: %d\n", numberofsolutio2(12));  
  return 0;
}

int numberofsolutio1(unsigned int num){

  int count = 0;
  int i;

  for(i=1; i<= num; i++)
    count += number1(i);

  return count;  
}

int number1(unsigned int num){
  
  int count = 0;
  
  while(num != 0){
    if(num % 10 == 1)
      ++count;
    num /= 10;
  }

  return count;
}

int numberofsolutio2(unsigned int num){

  int icount = 0;
  int ifactor = 1;
  int ilower = 0;
  int icurr = 0;
  int ihigh = 0;

  while(num / ifactor != 0){
    ilower = num - (num / ifactor) * ifactor;
    icurr  = (num / ifactor) % 10;
    ihigh =  num / (ifactor * 10);

    switch(icurr){
      case 0:
         icount += ihigh * ifactor;
         break;

     case 1:
         icount += ihigh * ifactor + ilower + 1;
         break;
       
     default:
         icount += (ihigh + 1) *ifactor;
         break;  
    } 
    ifactor *= 10;
  }
   return icount;
}
