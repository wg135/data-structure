/*
Write a function that returns true if the given Binary Tree is SumTree else false. A SumTree is a Binary Tree where the value of a node is equal to sum of the nodes present in its left subtree and right subtree. An empty tree is SumTree and sum of an empty tree can be considered as 0. A leaf node is also considered as SumTree.
*/

public class checksumtree{


  public static int sum(TreeNode T){
    if(T==null)
      return 0;
    else
      return sum(T.left) + T.data + sum(T.right);
  } 
  
  public static boolean check(TreeNode T){
    if(T == null)
      return true;
    if((T.left == null)&&(T.right == null))
      return true;

    int left_value, right_value;
    left_value = sum(T.left);
    right_value = sum(T.right);
  
    if((T.data == left_value+right_value)&&(check(T.left)&&check(T.right)))
      return true;
    else
      return false;
  }  

  public static void main(String[] args){
    TreeNode T = new TreeNode(26);
    T.left = new TreeNode(10);
    T.right = new TreeNode(3);
    T.left.left = new TreeNode(4);
    T.left.right = new TreeNode(6);
    T.right.right = new TreeNode(3);
    if(check(T))
      System.out.println("yes");
  }
}
