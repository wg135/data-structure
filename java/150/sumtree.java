/*Given a Binary Tree where each node has positive and negative values. Convert this to a tree where each node contains the sum of the left and right sub trees in the original tree. The values of leaf nodes are changed to 0.
*/

public class sumtree{

  public static int totree(TreeNode T){
    if(T== null)
      return 0;
    int old_value = T.data;
    T.data = totree(T.left) + totree(T.right);
    return old_value + T.data;
  }

  public static void main(String[] args){
    TreeNode T = new TreeNode(10);
    T.left = new TreeNode(-2);
    T.right = new TreeNode(6);
    T.left.left = new TreeNode(8);
    T.left.right = new TreeNode(-4);
    T.right.left = new TreeNode(7);
    T.right.right = new TreeNode(5);
    
  }
}
