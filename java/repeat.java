public class repeat{

  //print the array
  private static void printarray(int[] array){
    for(int i=0; i<array.length; i++){
      System.out.print(array[i] + " ");
    }
    System.out.print("\n");
  }

  private static void duplicate(int[] array){
   for(int i=0; i<array.length; i++){
      if(array[Math.abs(array[i])] > 0){
        array[Math.abs(array[i])] = -array[Math.abs(array[i])];
      }
      else
       System.out.print( i + " ");
    } 
    System.out.println();
  }
  public static void main(String[] args){

    int[] array = {1,2,3,1,3,0,6};
    printarray(array);
    duplicate(array);
  }
}
