import java.util.*;

public class ch4_6{

  public static TreeNode common(TreeNode T, TreeNode p, TreeNode q){
    if(ischild(T.left, p)&&ischild(T.left, q))
      return common(T.left, p, q);
    if(ischild(T.right, p)&&ischild(T.right, q))
      return common(T.right, p, q);

    return T;
  }

  public static boolean ischild(TreeNode T, TreeNode p){
    if(T == null)
      return false;
    if(T == p)
      return true;
    return (ischild(T.left, p)||ischild(T.right, p));
  }

   public static void inorder(TreeNode T){
    if(T == null)
      return;
    inorder(T.left);
    System.out.printf("%d ", T.data);
    inorder(T.right);
  }

  public static void main(String[] args){
      TreeNode T = new TreeNode(5);
      T.insert(3);
      T.insert(7);
      T.insert(2);
      T.insert(4);
      T.insert(6);
    
    TreeNode p = T.left.right;
    TreeNode q = T.right.left;
    
    TreeNode tmp = common(T, p, q);
    System.out.printf("%d\n", tmp.data);
  }
}


