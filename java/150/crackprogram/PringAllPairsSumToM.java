//Print All Pairs Sum To M In Sorted Array

public class PringAllPairsSumToM{

  public static void printall(int[] a, int num){
	int left = 0;
	int right = a.length-1;

	while(left < right){
	  if(a[left] + a[right] == num){
		System.out.printf("%d + %d = %d\n", a[left], a[right], num);
		left++;
		right--;
          }
          else if(a[left] + a[right] > num)
		right--;
	  else
	  	left++;
	}
  }
  public static void main(String[] args){
    int[] a = {1,2,3,4,9,9,10};
     printall(a, 12);
  }
}
