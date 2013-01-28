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
    public boolean hasPathSum(TreeNode root, int sum) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(root == null)
          return false;
          
        int tmp = sum - root.val;
        
        boolean result = false;
        if(root.left == null && root.right == null && (tmp == 0))
           result = true;
        return result || hasPathSum(root.left, tmp) ||hasPathSum(root.right, tmp);
          
          
        
    }
}
