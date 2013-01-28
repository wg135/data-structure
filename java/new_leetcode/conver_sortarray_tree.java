/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public TreeNode sortedArrayToBST(int[] num) {
        // Start typing your Java solution below
        // DO NOT write main() function
        TreeNode T;
        if((num.length == 0)||(num == null))
            return null;
       
        
        int left = 0;
        int right = num.length - 1;
        T = construct(num, left, right);
        return T;   
    }
    
    public TreeNode construct(int[] num, int start, int end){
        TreeNode T = null;
        if(start <= end){
            int middle = (start + end)/2;
            T = new TreeNode(num[middle]);  
        T.left = construct(num, start, middle - 1);
        T.right = construct(num, middle+1, end);
        }
        
        return T;
    }
}
