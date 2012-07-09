/*Given a sorted array arr[] and a number x, 
write a function that counts the occurrences of x in arr[]. 
Expected time complexity is O(Logn) 
*/
public class binaryoccurrences{

  public static int count(int[] a, int x){
    int i, j;
    
    i = first(a, 0, a.length, x);
    if(i==-1)
      return 0;
    j = last(a, 0, a.length, x);

    return j-i+1;
  }

  public static int first(int[] a, int low, int high, int x){
    while(low <= high){
      int mid = low + (high-low)/2;
      if(a[mid] < x)
        low = mid+1;
      if(a[mid] > x)
        high = mid-1;
      if(a[mid] == x){
        if((mid ==0)||(a[mid-1]<x))
          return mid;
         else
          high = mid-1;
      }       
    }
    return -1;    
  }

  public static int last(int[] a, int low, int high, int x){
    while(low<=high){
      int mid = low + (high-low)/2;
      if(a[mid]<x)
        low = mid+1;
      if(a[mid]>x)
        high = mid-1;
      if(a[mid]==x){
 	if((mid==0)||(a[mid+1]>x))
          return mid;
        else
          low = mid+1;
      }
    }
    return -1;
  }

  public static void main(String[] args){
    int[] a = {1, 1, 2, 2, 2, 2, 3};
    System.out.println(count(a, 2));
  }
}
