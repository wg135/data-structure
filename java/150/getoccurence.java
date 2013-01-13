//get the number of repeat elements in a sorted array

public class getoccurence{

  public static int getoccur(int[] array, int number){
    return getoccur_util(array, number, 0, array.length-1);
  }

  public static int getoccur_util(int[] array, int number, int start, int end){

    if(start > end)
      return 0;
    if(number > array[end]) //even the greatest element is less than number
      return 0;
    if(number < array[start]) //even the smallest element is greater than number
      return 0;
    
    
    int middle = start + (end - start)/2;
    if(array[middle] == number)
      return 1 + getoccur_util(array, number, start, middle-1) + getoccur_util(array, number, middle+1, end);
    else if(array[middle] < number) // check right side
      return getoccur_util(array, number, middle+1, end);
    else //check left side
      return getoccur_util(array, number, start, middle-1);
  }  

  public static void main(String[] args){
    int[] array = {1, 2, 3, 4, 5, 6, 7, 8, 8, 8, 8, 8, 8, 8, 9, 10, 11, 12};
    System.out.printf("there is %d 8\n", getoccur(array, 8));
    
  }
}
