//	Find Rotation In Sorted Array
public class FindShiftInRotatedArray{

  public static int find_shift(int[] a){

	int left = 0;
	int right = a.length - 1;
	
	while(left < right){
		if(a[left] < a[right])
			return right + 1;
		else{
			int middle = left + (right - left) / 2;
			if((a[left] < a[middle]) && (a[middle] > a[right]))
				return middle + 1;
			else if(a[left] < a[middle])
				left = middle + 1; //search right
			else // search left
				right = middle - 1;
		}
	}
       return -1;
  }
  public static void main(String[] args){
	int rotates[] = {3,4,5,1,2};
	System.out.printf("%d\n", find_shift(rotates));
  }  
}
