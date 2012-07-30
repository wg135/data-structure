

public class mirror{

  public static boolean check(TreeNode T){
    if(T == null)
      return true;
    else
      return checkutil(T.left, T.right);
  }
  
  public static boolean checkutil(TreeNode T1, TreeNode T2){
    if((T1==null)&&(T2 ==null))
      return true;
    if((T1==null)||(T2==null))
      return false;
     return checkutil(T1.left, T2.right)&&checkutil(T1.right, T2.left);
  }

  public static void main(String[] args){
    TreeNode T = new TreeNode(1);
    T.left = new TreeNode(2);
    T.left.right = new TreeNode(4);
    T.right = new TreeNode(3);
    T.right.left = new TreeNode(5);
    if(check(T))
      System.out.println("yes");
  } 
}
