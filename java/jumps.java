/*Given an array of integers where each element represents 
the max number of steps that can be made forward from that element. 
*/

import java.util.*;

public class jumps{
 
  public static int jump_dp(int[] array){
    int i, j;
    int[] jump = new int[array.length];

    jump[0] = 0;
    if((array.length == 0)||(array[0] == 0))
     return Integer.MAX_VALUE;
  
    for(i=1; i<array.length; i++){
      jump[i] = Integer.MAX_VALUE;
      for(j=0; j<i; j++){
        if(i<=j+array[j]&& jump[j] != Integer.MAX_VALUE){
           if(jump[i] > jump[j]+ 1)
             jump[i] = jump[j] + 1;
        }
      }
    }
    return jump[array.length-1];
  }

  public static void main(String[] args){
    int[] array = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    System.out.println(jump_dp(array));
  }
}
