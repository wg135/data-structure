import java.util.*;

public class bitonic{

  public static int check(int[] array){
    int i, j;
    int max;
    int[] li = new int[array.length];
    int[] ld = new int[array.length];
    
    Arrays.fill(li, 1);
    Arrays.fill(ld, 1);

  //compute increase subsequence
   for(i=1; i<array.length; i++)
     for(j=0; j<i; j++){
       if((array[j] < array[i])&&(li[i] < li[j]+ 1))
          li[i] = li[j] + 1;
     } 

  //compute decrease subsequence
  for(i=array.length-2; i>=0; i--)
    for(j=array.length-1; j>i; j--){
      if((array[j] < array[i])&&(ld[i] < ld[j]+1))
        ld[i] = ld[j]+1;
    }

  //compute max value
  max = li[0] + ld[0] - 1;
  for(i=1; i<array.length; i++){
    if(max < (li[i] + ld[i] - 1))
      max = li[i] + ld[i] -1;
  }

  return max;
  }
  public static void main(String[] args){
    int[] array = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    System.out.println(check(array));
  }
}
