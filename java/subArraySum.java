public class subArraySum{

  private static void printarray(int[] array){
    for(int i=0; i<array.length; i++){
      System.out.print(array[i] + " ");
    }
    System.out.print("\n");
  }

  private static int subarray(int[] array, int sum){
    
    int i =0, start=0;
    int curr_sum = array[0];

  for(i=1; i<array.length; i++){
    if(curr_sum == sum){
      System.out.println("from "+ start+ "to " + (i-1) +" is "+sum);
      return 1;
    }
    while((curr_sum > sum)&&(start < i -1)){
      curr_sum = curr_sum - array[start];
      start++;
    }
    if(curr_sum < sum){
      curr_sum = curr_sum + array[i];
    } 
  }    
  System.out.println("not match");
  return 0; 
  }

  public static void main(String[] args){
    
    int[] array = {15, 2, 4, 8, 9, 5, 10, 23};
    printarray(array);
    subarray(array, 23);
    
  }
}
