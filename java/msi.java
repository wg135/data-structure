/*
Given an array of n positive integers. 
Write a program to find the sum of maximum sum subsequence 
of the given array such that the intgers in the subsequence 
are sorted in increasing order. 
*/
import java.util.*;

public class msi{

  public static int msi_get(int[] array){
    int i, j;
    if(array.length == 0)
      return 0;

    int[] tmp = new int[array.length];
    Arrays.fill(tmp, 1);
    for(i=1; i<array.length; i++)
      for(j=0; j<i; j++){
        if((array[j] < array[i])&&(tmp[i] < tmp[j] + 1))
          tmp[i] = tmp[j] + 1;
      }    
    int max = 1;
    for(i=0; i<array.length; i++){
       if(max < tmp[i])
         max = tmp[i];
    }

   return max;
  }

  public static void main(String[] args){
    int[] array = {0, 22, 9, 33, 21, 50, 41, 60, 80};
    System.out.println(msi_get(array));
  }
}
