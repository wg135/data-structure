
//	SubTree Binary Tree Judging
public class TestSubBinaryTree{

  public static boolean subtree(TreeNode T1, TreeNode T2){
     if(T2 == null)
	return true;
     if(T1 == null)
	return false;

    if(T1.data == T2.data){
	if(subtree(T1.left, T2.left) && subtree(T1.right, T2.right))
	  return true;
    }	 
    else
	return subtree(T1.left, T2) || subtree(T1.right, T2);
  }

  public static void main(String[] args){
	TreeNode T = new TreeNoode(5);
	T.insert(3);
	T.insert(2);
	T.insert(4);
	T.insert(6);

        TreeNode T2 = new TreeNode(3);
	T2.insert(2);
	T2.insert(4);	
  }
}
