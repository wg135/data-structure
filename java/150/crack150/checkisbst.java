
public class checkisbst{

  public static boolean isbst(TreeNode T){
	if(T == null)
	  return true;
	return(isbst(T.left) && isbst(T.right) && lefttree(T.left, T.data) && righttree(T.right, T.data));
  }

  public static boolean lefttree(TreeNode T, int data){
	if(T == null)
	  return true;
	return(data > T.data) && lefttree(T.left, data) && lefttree(T.right, data);
  }

  public static boolean righttree(TreeNode T, int data){
	if(T == null)
	  return true;
	return(data < T.data) && righttree(T.left, data) && righttree(T.right, data);
  }

  public static void main(String[] args){
	TreeNode T = new TreeNode(1);
	T.left = new TreeNode(2);
	T.right = new TreeNode(3);

	if(isbst(T))
	  System.out.printf("yes\n");
  }
}
