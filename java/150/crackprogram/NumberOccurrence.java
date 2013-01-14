//Count Occurance in Sorted Array

public class  NumberOccurrence{

  public static int getoccurrence(int[] array, int k){
    return getoccurrence_util(array, k, 0, array.length-1);
  }

  public static int getoccurrence_util(int[] array, int k, int start, int end){
    if(k < array[start])
	return 0;  //less than the smallest element
    if(k > array[end])
	return 0; // great than the biggest element
    if(start > end) // don't forget return condition, silly!
	return 0; 

	int middle = start + (end - start) / 2;
	if(array[middle] == k)
	  return 1 + getoccurrence_util(array, k, start, middle-1) + getoccurrence_util(array, k, middle+1, end);
        else if(array[middle] > k) //search left
               return getoccurrence_util(array, k, start, middle-1);
             else // search right
	       return getoccurrence_util(array, k, middle+1, end);

    
  }

  public static void main(String[] args){
	int[] myNums = {1,1,2,2,2,2,2,2,3,4,5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7,8,9};
        System.out.printf("%d\n", getoccurrence(myNums, 2));
	System.out.printf("%d\n", getoccurrence(myNums, 6));
  }
}
