/*
Given a Binary Tree and a key, write a function that returns level of the key. 
*/

public class nodelevel{

  public static int getutil(TreeNode T, int data, int level){
    if(T == null)
      return 0;
    if(T.data == data)
      return level;
    int left, right;
    left = getutil(T.left, data, level+1);
    right = getutil(T.right, data, level+1);
    if(left != 0)
     return left;
    else
     return right;
  }

  public static int getlevel(TreeNode T, int data){
   return getutil(T, data, 1); 
  }

  public static void inorder(TreeNode T){
    if(T == null)
      return;
    inorder(T.left);
    System.out.printf("%d ", T.data);
    inorder(T.right);
  }

  public static void main(String[] args){
    TreeNode T = new TreeNode(3);
    T.left = new TreeNode(2);
    T.right = new TreeNode(5);
    T.left.left = new TreeNode(1);
    T.left.right = new TreeNode(4);
    System.out.printf("3 is in %d\n", getlevel(T, 3));
    System.out.printf("4 is in %d\n", getlevel(T, 4));
  }
}
