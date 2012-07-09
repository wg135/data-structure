/*
Given an unsorted array arr[] and two numbers x and y, 
find the minimum distance between x and y in arr[]. 
The array might also contain duplicates. 
You may assume that both x and y are different and present in arr[].
*/
public class distance{

  public static int dis(int[] a, int x, int y){
    int i, j;
    int result = Integer.MAX_VALUE;
    for(i=0; i<a.length; i++){
      for(j=i+1; j<a.length; j++){
        if(((a[i]==x && a[j]==y)||(a[i]==y && a[j]==x))&&(result> Math.abs(i-j)))
        result = Math.abs(i-j);
      }
    }
   return result;
  }

  public static int dis2(int[] a, int x, int y){
    int i;
    int result = Integer.MAX_VALUE;
    int prev = 0;

    for(i=0; i<a.length; i++){
      if((a[i]==x)||(a[i]==y)){
        prev = i;
        break;
      }
    } 
    while(i<a.length){
      if((a[i]==x)||(a[i]==y)){
	if((a[i] != a[prev])&&(result > (i-prev))){
	  result = i -prev;
          prev = i;
        }
        else
          prev = i;
      }
      i++;
    }

    return result;
  }

  public static void main(String[] args){
    int[] a = {3, 5, 4, 2, 6, 5, 6, 6, 5, 4, 8, 3};
    System.out.println(dis(a, 3, 6));
    System.out.println(dis2(a, 3, 6));
  }
}
