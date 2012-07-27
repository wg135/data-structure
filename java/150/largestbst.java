/*
Given a Binary Tree, write a function that returns the size of the largest subtree which is also a Binary Search Tree (BST). If the complete Binary Tree is BST, then return the size of whole tree.
*/

public class largestbst{

  public static int cnt(TreeNode T){
    if(isbst(T))
      return size(T);
    else
      return Math.max(cnt(T.left), cnt(T.right));
  }

  public static boolean isbst(TreeNode T){
   return isbstutil(T, Integer.MIN_VALUE, Integer.MAX_VALUE); 
  }  
  
  public static boolean isbstutil(TreeNode T, int small, int large){
    if(T == null) 
      return true;
    
    if(T.data < small || T.data > large)
      return false;
    
    return isbstutil(T.left, small, T.data-1)&&isbstutil(T.right, T.data+1, large);
  }

  public static int size(TreeNode T){
    if(T == null)
      return 0;
    else
      return(size(T.left)+ size(T.right)+1);
  }

  public static void main(String[] args){
    TreeNode T = new TreeNode(5);
    T.left = new TreeNode(2);
    T.right = new TreeNode(4);
    T.left.left = new TreeNode(1);
    T.left.right = new TreeNode(3);
   
    System.out.println(cnt(T));
 }
}
