public class Solution {
    public int removeElement(int[] A, int elem) {
        // Start typing your Java solution below
        // DO NOT write main() function
        
        int i =0;
        int j = A.length-1;
        
        while(i <= j){
            while(i<=j && A[i] != elem)
                i++;
            while(i<=j && A[j] == elem)
                j--;
            
            if(i > j)
              break;
            swap(A, i, j);
            i++;
            j--;
            
        }
        return i;   
    }
    
    public void swap(int[] A, int i, int j){
        int tmp;
        tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
    }
}
