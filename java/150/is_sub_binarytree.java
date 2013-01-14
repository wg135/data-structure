//SubTree Binary Tree Judging

public class is_sub_binarytree{

  public static boolean issubtree(TreeNode T1, TreeNode T2){
    if(T1 == null)
	return false;
    if(T2 == null)
	return true;
   
    if(T1.data == T2.data){
	if(issubtree(T1.left, T2.left)&&issubtree(T1.right, T2.right));
 	  return true;
    }
    else
	return issubtree(T1.left, T2)|| issubtree(T1.right, T2);
  }
  
  public static void main(String[] args){
    TreeNode T1 = new TreeNode(1);
    T1.left = new TreeNode(2);
    T1.right = new TreeNode(3);
    T1.left.left = new TreeNode(4);
    T1.left.right = new TreeNode(5);

    TreeNode T2 = new TreeNode(2);
    T2.left = new TreeNode(4);
    T2.right = new TreeNode(5); 
    if(issubtree(T1, T2))
	System.out.printf("yes\n");
  }
}
