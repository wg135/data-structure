//Rotate Array In Place
public class ArrayInplaceRotate{

  public static void rotate(int[] a, int k){
	reverse(a, 0, k - 1);
	reverse(a, k, a.length - 1);
	reverse(a, 0, a.length - 1);
  }

  public static void reverse(int[] a, int start, int end){
	if(start > end)
	  return;
	for(int i = start; i<= ((end - start) / 2 + start); i++){
	  swap(a, i, (end - i + start));
	}
  }

  public static void swap(int[] a, int start, int end){
	int tmp = a[start];
	a[start] = a[end];
	a[end] = tmp;
  }

  public static void main(String[] args){
	int[] a = {1,2,3,4,5,6};	
	rotate(a, 3);
	for(int tmp : a)
	  System.out.printf("%d ", tmp);
	System.out.printf("\n");

  }
}
