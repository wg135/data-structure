import java.util.*;

public class isbst{

  public static boolean leftsubtree(TreeNode T, int data){
    if(T == null)
      return true;

    return((T.data < data)&&(leftsubtree(T.left, data))&&(leftsubtree(T.right, data)));
  }

  public static boolean rightsubtree(TreeNode T, int data){
    if(T == null)
      return true;

    return((T.data>data)&&(rightsubtree(T.left, data))&&(rightsubtree(T.right, data)));
  }

  public static boolean isbinary(TreeNode T){
    if(T == null)
      return true;
    return(leftsubtree(T.left, T.data)&&
           rightsubtree(T.right, T.data)&&
           isbinary(T.left)&&
           isbinary(T.right));
  }

  public static boolean isbinary2(TreeNode T){
    return check1(T, Integer.MIN_VALUE, Integer.MAX_VALUE);
  }

  public static boolean check1(TreeNode T, int low, int high){
    if(T == null)
     return true;
    if((T.data > low)&&(T.data <high))
      return(check1(T.left, low, T.data)&&check1(T.right, T.data, high));
    else
      return false;
  }

  public static void main(String[] args){
    TreeNode T = new TreeNode(5);
    T.insert(3);
    T.insert(7);
    T.insert(2);
    T.insert(4);
    T.insert(6);
    if(isbinary(T))
      System.out.print("yes\n");
    else
      System.out.print("no\n");
    
   if(isbinary2(T))
     System.out.print("yes\n");
    else
      System.out.print("no\n");
    
  }
}
