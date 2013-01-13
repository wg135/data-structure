//Print all pairs in a sorted array that sum to M  
public class sumsorted{

  public static void print(int[] sorted, int sum){
    int left = 0;
    int right = sorted.length-1;
    
    while(left < right){
      int tmp = sorted[left] + sorted[right];
      if(tmp == sum){
        System.out.printf("%d + %d\n", sorted[left], sorted[right]);
        left++;
        right--;
      }
      else if(tmp > sum)
	    right--;
        else
	   left++;
    }
  }

  public static void main(String[] args){
    int[] sorted = {1, 2, 3, 4, 8, 9, 10};
     print(sorted, 12);
  }
}
