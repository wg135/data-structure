/*Given an array of n distinct integers sorted in ascending order, 
write a function that returns a Fixed Point in the array, 
if there is any Fixed Point present in array, else returns -1. 
Fixed Point in an array is an index i such that arr[i] is equal to i. 
Note that integers in array can be negative. 
*/
import java.util.*;

public class fixedpoint{

  public static int binsearch(int[] a, int low, int high){
    while(low<=high){
      int mid = low + (high -low)/2;
      if(mid == a[mid])
        return mid;
      if(a[mid] > mid)
        high = mid -1;
      if(a[mid] < mid)
        low = mid + 1;
    }
    return -1;
  }

  public static void main(String[] args){
    int[] a = {-10, -5, 0, 3, 7};
    System.out.println(binsearch(a, 0, a.length-1));
  }
}
