public class FindFirstIndex{

  public static int findfirst(int[] a, int k){
	return findfirst_util(a, 0, a.length-1, k);
  }

  public static int findfirst_util(int[] a, int start, int end, int k){
    if(a[0] > k)
	return -1;
    if(a[a.length-1] < k)
	return -1;
    if(a[start] == k)
	return start;
    int middle = start + (end - start) / 2;
    if(a[middle] == k){
	int leftindex = findfirst_util(a, start, middle-1, k);
        return (leftindex == -1? middle : leftindex);
    }
    else if(a[middle] > k) //search left
	return findfirst_util(a, start, middle-1, k);
    else //search right
	return findfirst_util(a, middle+1, end, k);
  }

  public static void main(String[] args){
	int[] a = {1,2,2,3,3,3,3,3,3,3,3,4,5,6,7,8,9};
	System.out.printf("%d\n", findfirst(a, 3));
  }
}
