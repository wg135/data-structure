//	Reconstruct Binary
public class ReConstructBinaryTree{

  public static TreeNode conbinary(int[] pre, int pre_start, int pre_end, int[] in, int in_start, int in_end){

	if(pre_start > pre_end)
	  return null;
	if(pre_start == pre_end)
	  return (new TreeNode(pre[pre_start]));
	
	int root_index = 0;
	for(int i = in_start; i<=in_end; i++){
	  if(pre[pre_start] == in[i]){
	    root_index = i;
	    break;
	  }
	}
	
        int leftcount = root_index - in_start;
//	int rightcount = in_end - root_index;
	
	TreeNode T = new TreeNode(in[root_index]);
	T.left = conbinary(pre, pre_start + 1, pre_start + leftcount, in, in_start, in_start + leftcount - 1);
	T.right = conbinary(pre, pre_start + leftcount + 1, pre_end, in, in_start + leftcount + 1, in_end);

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
	int[] preOder = {1,2,3,4,5};
	int[] inOrder = {2,1,4,3,5};
	TreeNode T = conbinary(preOder, 0, 4, inOrder, 0, 4);
        inorder(T);	
  }
}
