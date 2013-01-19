//Longest Increasing Subsequence
import java.util.*;

public class LIS{

  public static int get_lis(int[] a){
	if ((a.length == 0) || (a.length == 1))
		return a.length;
	int[] tmp = new int[a.length];
	String[] path = new String[a.length];
    
	
	Arrays.fill(tmp, 1);
	for(int m = 0; m < a.length; m++){
	  path[m] = a[m] + " ";
	}

        for(int i = 1; i < a.length; i++){
	  for(int j = 0; j < i; j++){
		if((a[i] > a[j]) && (tmp[i] < tmp[j] + 1)){
			tmp[i] = tmp[j] + 1;
		        path[i] = path[j] + a[i] + " ";	
		}
	  }
	}
        int max = Integer.MIN_VALUE;
	int index = 0;
	for(int k = 0; k < a.length; k++){
	  if(tmp[k] > max){
	    max = tmp[k];
            index = k;
 	  }
	}
	
       System.out.printf("%s\n", path[index]);

      return max;
  }

  public static void main(String[] args){
	int[] a = {0, 22, 9, 33, 21, 50, 41, 60, 80};
     	System.out.printf("%d\n", get_lis(a));
  }
}
