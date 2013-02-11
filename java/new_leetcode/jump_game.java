public class Solution {
    public boolean canJump(int[] A) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(A.length == 0)
          return false;
        if(A.length == 1)
          return true;
          
        boolean result = false;
        int count = 0;
        
        for(int i = A.length - 2; i>=0; i--){
            if(A[i] > count){
                result = true;
                count = 0;
            }
            else{
                result = false;
                count++;
            }
        }
        return result;
    }
}
