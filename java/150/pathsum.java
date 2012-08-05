public class pathsum{

  public static boolean check(TreeNode T, int sum){
    if(T == null)
      return (sum == 0);
    else{
      boolean result = false;
      int subsum = sum - T.data;
      if((subsum ==0)&&(T.left ==null)&&(T.right == null))
        return true;
      if(T.left != null)
        result = result || check(T.left, subsum);
      if(T.right != null)
        result = result || check(T.right, subsum);
      return result;
    }
  }
  public static void main(String[] args){
    TreeNode T = new TreeNode(10);
    T.left = new TreeNode(8);
    T.right = new TreeNode(2);
    T.left.left = new TreeNode(3);
    T.left.right = new TreeNode(5);
    T.right.left = new TreeNode(2);
    if((check(T, 21)))
      System.out.println("yes");
  }
}
