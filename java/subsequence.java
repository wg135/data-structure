import java.util.*;

public class subsequence{

  public static boolean check(int[] array){
    int[] small = new int[array.length];
    int[] big = new int[array.length];
    int min = 0;
    int max = array.length-1;
    
    small[0] = -1;
    for(int i=1; i<array.length; i++){
       if(array[min] < array[i]){
         small[i] = min;
       }
       else{
          small[i] = -1;
          min = i;
       }
    }
    big[max-1] = -1;
    for(int j=max-2; j>=0; j--){
      if(array[max] > array[j]){
         big[j] = max;
      }
      else{
         big[j]=-1;
         max = j;
       
    }
  }
  for(int k=0; k<array.length; k++){
    if(small[k] != -1 && big[k] != -1)
      return true;
  }
  return false;
  }

  public static void main(String[] args){
    int[] array = {12, 11, 10, 5, 6, 2, 30};
    if(check(array))
      System.out.println("yes");
  }
}
