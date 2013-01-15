
public class VerifyBST{

  public static boolean isbst(TreeNode T){
    if(T == null)
	return true;
    else
	return isbst(T.left) && isbst(T.right) && check_left(T.data, T.left) && check_right(T.data, T.right);
  }

  public static boolean check_left(int data, TreeNode T){
    if(T == null)
	return true;
    else
	return(data > T.data) && check_left(data, T.left) && check_left(data, T.right);
  }

  public static boolean check_right(int data, TreeNode T){
    if(T == null)
	return true;
    else
	return (data < T.data) && check_right(data, T.left) && check_right(data, T.right);	
  }

  public static void main(String[] args){
    TreeNode T = new TreeNode(5);
    T.insert(3);
    T.insert(7);
    T.insert(2);
    T.insert(4);
    T.insert(6);
    if(isbst(T))
      System.out.print("yes\n");
    else
      System.out.print("no\n");

  }
}
