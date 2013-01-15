//	Find Closest Value In Binary Search Tree
public class FindClosest{

  public static int min_diff(TreeNode T, int num){
        if(T == null)
	  return num;
	else
	  return diff_tree(T, num) + num; // return the value of the node data	
  }

  public static int diff_tree(TreeNode T, int num){
	if(T == null)
	  return Integer.MAX_VALUE;	
        if(T.data < num) // in root or in right tree
	  return smalldiff(T.data - num, diff_tree(T.right, num));
        else // in root or in left tree
	  return smalldiff(T.data - num, diff_tree(T.left, num));
  }

  public static int smalldiff(int a, int b){
	if(Math.abs(a) > Math.abs(b))
		return b;
	else
		return a;
  }

  public static void main(String[] args){
	TreeNode T = new TreeNode(100);
	T.insert(50);
	T.insert(10);
	T.insert(60);
	T.insert(200);
	T.insert(150);
	T.insert(300);
	System.out.printf("%d\n", min_diff(T, 120));
  }
}
