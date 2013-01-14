//Longest Increasing Subsequence
public class lis{


  public static int getlis(int[] a){
    if(a.length == 1)
	return 1;
    int[] tmp = new int[a.length];
    for(int i=0; i<a.length; i++)
	tmp[i] = 1;

   
    for(int i=1; i<a.length; i++){
      for(int j=0; j<i; j++){
	if((a[i] > a[j]) && (tmp[i] < tmp[j] + 1))
	  tmp[i] = tmp[j] + 1;
      }
    } 
    int max = Integer.MIN_VALUE;

    for(int i=0; i<tmp.length; i++){
	if(max < tmp[i])
	   max = tmp[i];
    }
    return max;
  }

  public static void main(String[] args){
   int[] a = {0, 22, 9, 33, 21, 50, 41, 60, 80};
   System.out.printf("%d\n", getlis(a));
  }
}
