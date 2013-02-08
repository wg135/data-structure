/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
import java.util.*;

public class Solution {
    public boolean isBalanced(TreeNode root) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(root == null)
          return true;
        
        if (Math.abs(tree_max(root.left) - tree_max(root.right)) >= 2)
          return false;
        
        return isBalanced(root.left) && isBalanced(root.right);
    }

    public int tree_max(TreeNode root){
        if(root == null)
          return 0;
        else
          return (1 + Math.max(tree_max(root.left), tree_max(root.right)));
    }
    
   
}
