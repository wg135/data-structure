/*Given an array of n elements which contains elements from 0 to n-1, 
with any of these numbers appearing any number of times. 
Find these repeating numbers in O(n) and using only constant memory space.
*/

import java.util.*;

public class duplicates{

  public static void dup(int[] a){
    int i;
    for(i=0; i<a.length; i++){
      if(a[Math.abs(a[i])] >= 0)
       a[Math.abs(a[i])] = -a[Math.abs(a[i])];
      else
       System.out.println(Math.abs(a[i]));       
    }    
  }

  public static void main(String[] args){
    int[] a = {1, 2, 3, 1, 3, 0, 6};
    dup(a);
  }
} 
