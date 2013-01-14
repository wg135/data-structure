//Reconstruct Binary

public class reconstructbinarytree{

    public static void inorder(TreeNode T){
    if(T == null)
      return;
    inorder(T.left);
    System.out.printf("%d ", T.data);
    inorder(T.right);
  }

  public static TreeNode construct(int[] pre, int[] in){
    
    return construct_util(pre, 0, pre.length-1, in, 0, in.length-1);
  }
  
  public static TreeNode construct_util(int[] pre, int pre_start, int pre_end, int[] in, int in_start, int in_end){
    if(pre_start > pre_end)
	return null;
    if(pre_start == pre_end)
	return (new TreeNode(pre[pre_start]));

   int root_index = 0;
   for(int i=in_start; i<=in_end; i++){
	if(in[i] == pre[pre_start]){
	  root_index = i;
	  break;
        }
    } 
  
    int leftcount = root_index - in_start; //number of element in left tree
//    int rightcount = in_end - root_index;  //number of element in right tree
   
    TreeNode T = new TreeNode(pre[pre_start]);

    T.left = construct_util(pre, pre_start+1, pre_start + leftcount, in, in_start, in_start +leftcount-1);
    T.right = construct_util(pre, pre_start+leftcount+1, pre_end, in, in_start+leftcount+1, in_end);

    return T;
  
  }

  public static void main(String[] args){
    int[] pre = {1,2,3,4,5};
    int[] in = {2,1,4,3,5};

    TreeNode tree = construct(pre, in);	  
    inorder(tree);
  }
}

  
