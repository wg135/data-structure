
public class onlyonce{

//a unique number in an array, other elements has two 
  public static int onlyone(int[] a){
	int result = a[0];

        for(int i=1; i<a.length; i++)
	  result ^= a[i];

	return result;	
  }

// there are two unique number is an array, other element has two
  public static void onlyone_two(int[] a){
  
      int result = 0;
      for(int i=0; i<a.length; i++)
	result ^= a[i];

      int num1 = 0;
      int num2 = 0;
      int i = 1;
      int count = 1;

      while(true){  //find out the first different bit
	if((result & i) == 1)
	  break;
	else{
	  result = result>>1;
	  count = count<<1;
	}
	   
      }

     for(i =0; i<a.length; i++){// divide the array into two base on the first different bit
	if((a[i] &count) == 0)
	   num1 ^= a[i];
	else
	   num2 ^= a[i];
     }

    System.out.printf("%d, %d\n", num1, num2);
  }

  public static void main(String[] args){
	int[] a = {2, 1, 3, 4, 5, 2, 3, 4, 5};
	System.out.printf("%d\n", onlyone(a));
 	int[] b = {2, 1, 3, 4, 5, 2, 3, 4, 5, 7};	
	onlyone_two(b);
  }
}
