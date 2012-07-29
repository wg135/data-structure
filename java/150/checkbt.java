/*
Given two binary trees, check if the first tree is subtree of the second one. A subtree of a tree T is a tree S consisting of a node in T and all of its descendants in T. The subtree corresponding to the root node is the entire tree; the subtree corresponding to any other node is called a proper subtree
*/

public class checkbt{

  public static boolean istree(TreeNode T, TreeNode S){
    if(S==null)
      return true;
    if(T == null)
      return false;

    if(check(T, S))
      return true;

     return (check(T.left, S)||check(T.right, S));
  }
  
  public static boolean check(TreeNode T, TreeNode S){
    if((T == null)&&(S==null))
      return true;
    if(T.data != S.data)
      return false;
    else
      return check(T.left, S.left)&&check(T.right, S.right);    
  }

  public static void main(String[] args){
    TreeNode S = new TreeNode(10);
    S.left = new TreeNode(4);
    S.right = new TreeNode(6);
    S.left.right = new TreeNode(30);

    TreeNode T = new TreeNode(26);
    T.left = new TreeNode(10);
    T.right = new TreeNode(3);
    T.left.left = new TreeNode(4);
    T.left.right = new TreeNode(6);
    T.right.right = new TreeNode(3);
    T.left.left.right = new TreeNode(30);
    
    if(istree(T, S))
      System.out.println("yes");
  }
}
