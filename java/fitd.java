/*
Given an array of integers which is initially increasing and then decreasing, 
find the maximum value in the array.
*/

public class fitd{

  public static int max(int[] a, int low, int high){
    //only one element in array
    if(low == high)
      return a[low];
   
    //two elements in array
    if(high == low+1){
      if(a[high] > a[low])
        return a[high];
      else
        return a[low];
    }
    
    while(low <=high){
      int mid = low + (high-low)/2;
      if((a[mid] > a[mid-1])&&(a[mid]>a[mid+1]))
        return a[mid];
      if((a[mid]>a[mid-1])&&(a[mid]<a[mid+1]))
        low = mid + 1;
      if((a[mid]<a[mid-1])&&(a[mid]>a[mid+1]))
        high = mid -1;
         
    }
    return -1;
    
  }

  public static void main(String[] args){
    int[] a = {8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1};
    System.out.println(max(a, 0, a.length-1));
   
  }
}
