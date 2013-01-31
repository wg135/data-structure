import java.util.*;

public class Solution {
    public int maxSubArray(int[] A) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int sum = 0;
        int max = Integer.MIN_VALUE;
        
        for(int i=0; i<A.length; i++){
            sum += A[i];
            if(max < sum)
                max = sum;
            if(sum < 0)
                sum = 0;
        }
        
        return max;
    }
}
