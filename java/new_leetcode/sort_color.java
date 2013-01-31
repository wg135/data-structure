public class Solution {
    public void sortColors(int[] A) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(A.length <= 1)
            return;
        
        int i=0;
        int j = A.length - 1;
        int curr = i;
        
        while(curr <= j){
            if(A[curr] == 0){
                if(curr > i){
                    swap(A, i++, curr);
                }else{
                    ++curr;
                    ++i;
                }
            }
            else if(A[curr] == 2){
                if(curr < j){
                    swap(A, j--, curr);
                }
                else{
                    return;
                }
            }
            else
            ++curr;
        }
        
    }
    
    public void swap(int[] a, int i, int j){
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
}
