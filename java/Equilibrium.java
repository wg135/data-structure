/*Equilibrium index of an array is an index such that the sum of elements 
at lower indexes is equal to the sum of elements at higher indexes
*/

import java.util.*;

public class Equilibrium{

  public static int equi1(int[] a){
    int i, j;
    int left, right;
    for(i=0; i<a.length; i++){
       left = 0;
       right = 0;
      for(j=0; j<i; j++)
        left += a[j];
      for(j=i+1; j<a.length; j++)
        right += a[j];

      if(left == right)
        return i;
    }
    return -1;
  }

  public static int equi2(int[] a){
    int i, sum = 0, left = 0;

    for(i=0; i<a.length; i++)
      sum += a[i];
   
    for(i=0; i<a.length; i++){
      sum -= a[i];
    if(sum == left)
      return i;
    else
      left += a[i];
    }
    
    return -1;    
  }
  public static void main(String[] args){
    int[] a = {-7, 1, 5, 2, -4, 3, 0};
    System.out.println(equi1(a));
    System.out.println(equi2(a));
  }
}
