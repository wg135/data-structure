import java.util.*;

public class lcabst{

  public static TreeNode find(TreeNode T, TreeNode t1, TreeNode t2){
    if((T==null)||(t1==null)||(t2==null))
      return null;
    if(Math.max(t1.data, t2.data)< T.data)
      return find(T.left, t1, t2);
    else if(Math.min(t1.data, t2.data)>T.data)
      return find(T.right, t1, t2);
    else
      return T;
  }

  public static void main(String[] args){
    TreeNode T = new TreeNode(5);
    T.insert(3);
    T.insert(7);
    T.insert(2);
    T.insert(4);
    T.insert(6);
    System.out.printf("%d\n", find(T, T.left.left, T.left.right).data);
  } 
}
