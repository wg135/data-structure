//Verify if a binary tree is a Binary Search Tree (BST)
public class check_bst{

  public static boolean isbst(TreeNode T){
    if(T == null)
	return true;
    else
	return isbst(T.left) && isbst(T.right) && check_left(T.left, T.data) && check_right(T.right, T.data);    
  }
  
  public static boolean check_left(TreeNode T, int data){
    if(T == null)
	return true;
    else
	return (T.data < data) && check_left(T.left, data) && check_left(T.right, data);   
  }

  public static boolean check_right(TreeNode T, int data){
    if(T == null)
	return true;
    else
	return (T.data > data) && check_right(T.left, data) && check_right(T.right, data);

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
