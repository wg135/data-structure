public class Solution {
    public int jump(int[] A) {
        /* Greedy algorithm: always jump to the next place which
         * provides you the maximum next jump*/
         
        int max = A[0]; //the max index of the next jump
        int min = 1; //the min index of the next jump
        int step = 0;
 
        if (A.length == 1) {
            return 0;
        }
        
        while (max < A.length-1) {
            int m = max;
            for (int i = min; i <= max; i++) {
                if (m < A[i] + i) {
                    m = A[i] + i;
                }
            }
            min = max+1;
            max = m;
            step++;
        }
 
        return step+1;
    }
}    
