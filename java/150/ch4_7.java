import java.util.*;

public class ch4_7{
    
  public static boolean iscontain(TreeNode T1, TreeNode T2){
    if(T2 == null)
      return true;
    else
      return subtree(T1, T2);
  }
  
  public static boolean subtree(TreeNode T1, TreeNode T2){
    if(T1 == null)
      return false;

    if(T1.data == T2.data)
     if(match(T1, T2))
       return true;

    return(subtree(T1.left, T2)||subtree(T1.right, T2));
  }
  
  public static boolean match(TreeNode T1, TreeNode T2){
    if((T1==null)&&(T2 == null))
      return true;
    if((T1 ==null)||(T2 ==null))
      return false;
    if(T1.data != T2.data)
      return false;

    return(match(T1.left, T2.left)&&match(T1.right, T2.right));
  }

  public static void main(String[] args){
    TreeNode T1 = new TreeNode(5);
    T1.insert(3);
    T1.insert(7);
    T1.insert(2);
    T1.insert(4);
    T1.insert(6);

    TreeNode T2 = new TreeNode(5);
    T2.insert(3);
    T2.insert(7);
    T2.insert(2);
    T2.insert(4);
    T2.insert(6);

   if(iscontain(T1, T2))
    System.out.println("yes");

  }
}
