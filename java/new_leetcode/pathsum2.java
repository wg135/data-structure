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
    public ArrayList<ArrayList<Integer>> pathSum(TreeNode root, int sum) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
        ArrayList<Integer> path = new ArrayList<Integer>();
        
        pathsum(root, sum, path, result);
        return result;
    }
    
    public void pathsum(TreeNode root, int sum, ArrayList<Integer> path, ArrayList<ArrayList<Integer>> result){
        if(root == null)
            return;
            
        if(root.left == null && root.right == null && sum == root.val){
            ArrayList<Integer> p = new ArrayList<Integer>();
            p.addAll(path);
            p.add(root.val);
            result.add(p);
            return;
        }    
        
        path.add(root.val);
        pathsum(root.left, sum-root.val, path, result);
        pathsum(root.right, sum-root.val, path, result);
        path.remove(path.size()-1); 
        
        
    }
}
