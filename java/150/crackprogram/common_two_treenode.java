
public class common_two_treenode{

  public static TreeNode common(TreeNode T, TreeNode p, TreeNode q){
	if(ischild(T.left, p) && ischild(T.left, q))
	  return common(T.left, p, q);
	if(ischild(T.right, p) && ischild(T.right, q))
	  return common(T.right, p, q);

	return T;
  }

  public static boolean ischild(TreeNode T, TreeNode q){
	if(T == null)
	  return false;
	if(T == q)
	  return true;
	
	return ischild(T.left, q) || ischild(T.right, q);
  }

  public static void main(String[] args){
	TreeNode T = new TreeNode(1);
	T.left = new TreeNode(2);
	T.right = new TreeNode(3);
	TreeNode tree = common(T, T.left, T.right);
	System.out.printf("%d\n", tree.data);
  }
}
