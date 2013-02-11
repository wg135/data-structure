public class Solution {
    public int[] searchRange(int[] A, int target) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int[] result = new int[2];
        result[0] = bs(A, target-1) + 1;
        result[1] = bs(A, target);
        
        if(result[1] == -1 ||A[result[1]] != target){
            result[0] = -1;
            result[1] = -1;
        }
        
        return result;
        
    }
    
    public int bs(int[] A, int target){
        int start = 0;
        int end = A.length - 1;
        int mid = (start + end) / 2;
        int result = -1;
        
        while(start <= end){
            if(A[mid] > target){
                end = mid - 1;
                mid = (start + end) / 2;
            }
            else{
                start = mid + 1;
                result = mid;
                mid = (start + end) / 2;
            }
        }
        return result;
    }
}
