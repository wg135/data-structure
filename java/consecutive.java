/*Given an unsorted array of numbers, 
write a function that returns true if array consists of consecutive numbers.
*/

import java.util.*;

public class consecutive{
  
  public static int max(int[] a){
     int max = Integer.MIN_VALUE;
     for(int i=0; i<a.length; i++){
       if(max < a[i])
         max = a[i];
     }
     return max;
  }

  public static int min(int[] a){
    int min = Integer.MAX_VALUE;
    for(int i=0; i<a.length; i++){
      if(min > a[i])
        min = a[i];
    }
    return min;
  }

  public static boolean check(int[] a){
    int min_c, max_c;
    boolean[] visited = new boolean[a.length];
    int i;

    min_c = min(a);
    max_c = max(a);
    if(max_c - min_c + 1 == a.length){
      for(i=0; i<a.length; i++){
	if(visited[a[i]-min_c] == true)
          return false;
        visited[a[i]-min_c] = true;
      }
      return true;      
    }
    else
       return false;    
  }  
 
  public static void main(String[] args){
    int[] a = {83, 78, 80, 81, 79, 82};
    if(check(a))
      System.out.println("yes");
  }
}
