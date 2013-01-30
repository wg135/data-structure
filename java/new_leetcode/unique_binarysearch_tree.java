public class Solution {
    public int numTrees(int n) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(n<=1)
            return n;
        
        int[] result = new int[n+1];
        result[0] = 1;
        result[1] = 1;
        
        for(int i=2; i<=n; i++){
            for(int j=0; j<i; j++){
                int left = result[j];
                int right = result[i - j - 1];
                result[i] += left *right;

            }
        }
        
        return result[n];
    }
}
