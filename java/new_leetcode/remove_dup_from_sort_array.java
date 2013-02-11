public class Solution {
    public int removeDuplicates(int[] A) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int len = A.length;
        int j =0;
        if(len == 0)
          return 0;
        
        for(int i=0; i<len; ){
            while(i<len && A[i] == A[j]){
                i++;
            }
            if(i < len)
              A[++j] = A[i];
        }
        return j+1;
        
    }
}
