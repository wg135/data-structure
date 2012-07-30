/*
*/

public class sortorder{

 public static void print(int[] a, int start, int end){
    if(start > end)
      return;
    print(a, start*2+1, end);
    System.out.printf("%d ", a[start]);
    print(a, start*2+2, end);
  }
  public static void main(String[] args){
   int[] a = {4,2,5,1,3}; 
   print(a, 0, a.length-1);
   System.out.printf("\n"); 
  }
}
