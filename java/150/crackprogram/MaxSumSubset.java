//Find Max Sum Subset In Array
public class MaxSumSubset{

  public static int maxsum(int[] a){
    int maxend = 0;
    int maxsofar = 0;
    int maxsofar_old = 0;
    int curr = 0;
    int next = 0;
    int tmp_index = 0;

    for(int i=0 ; i<a.length; i++){
	maxsofar = maxsofar_old + a[i];
	if(maxsofar > 0){
		maxsofar_old = maxsofar;
		if(maxsofar > maxend){
			maxend = maxsofar;
			curr = tmp_index;
			next = i;
		}
        }
        else{
	  maxsofar_old = 0;	
	  tmp_index = i+1;	
	}
    }
    return maxend;
  }
  public static void main(String[] args){
    int[] nums = {-1,2,3,5,-2};
    System.out.printf("%d\n", maxsum(nums));		
  }
}
