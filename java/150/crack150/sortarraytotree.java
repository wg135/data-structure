//build a binary tree from a sorted array
public class sortarraytotree{

  public static TreeNode build(int[] a){
	return build_util(a, 0, a.length-1);
  }

  public static TreeNode build_util(int[] a, int start, int end){
	if(start > end)
	  return null;
	
	int middle = (end - start)/2 + start;
  	TreeNode T = new TreeNode(a[middle]);
	T.left = build_util(a, start, middle - 1);
	T.right = build_util(a, middle + 1, end);
	
	return T;
  }

  public static void inorder(TreeNode T){
	if(T == null)
	  return;
	inorder(T.left);
	System.out.printf("%d ", T.data);
	inorder(T.right);
  }

  public static void main(String[] args){
	int[] a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	TreeNode T = build(a);
	inorder(T);
	System.out.printf("\n");

	
  }
}
