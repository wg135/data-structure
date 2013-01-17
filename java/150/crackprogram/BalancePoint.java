//Find Balance Point in Array
public class BalancePoint{

  public static int balance(int[] a){
	int left =a[0];
	int right = 0;
	for(int i=0; i<a.length; i++)
	  right += a[i];

	for(int i=0; i<(a.length-1); i++){
	   if(left == right)	
		return i;
           left += a[i+1];
	   right -= a[i];
	}
	return -1; //not found
  }
	
  public static void main(String[] args){
	int[] a = {1,2,3,7,6,5,9,5,6,7,5,2,-1};//expected 6th position
	System.out.printf("%d\n", balance(a));	
  }
}
