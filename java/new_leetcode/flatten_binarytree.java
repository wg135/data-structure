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
    public void flatten(TreeNode root) {
        // Start typing your Java solution below
        // DO NOT write main() function
        TreeNode runner = root;
        if(runner == null)
            return;
        
        while(runner != null){
            if(runner.left != null){
                findrightmostchild(runner.left).right = runner.right;
                runner.right = runner.left;
                runner.left = null;
            }
            runner = runner.right;
        }
        
    }
    
    public TreeNode findrightmostchild(TreeNode root){
        while(root.right != null){
            root = root.right;
        }
        return root;
    }
}
