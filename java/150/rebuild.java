public class rebuild{

  static int preindex = 0;
  public static TreeNode reBuild(int[] inorder_array, int[] preorder_array, int left, int right){
  
  if(left > right)
    return null;
  if(preindex >= inorder_array.length)
    return null;
  
  int i;
  int val = preorder_array[preindex];
  preindex++;

  TreeNode T = new TreeNode(val);
  for(i = left; i<right; i++){
    if(inorder_array[i] == val)
      break;
  }
  T.left = reBuild(inorder_array, preorder_array, left, i-1);
  T.right = reBuild(inorder_array, preorder_array, i+1, right);

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
    int[] inorder_array = {2, 3, 4, 5, 6, 7};
    int[] preorder_array = {5, 3, 2, 4, 7, 6};
    TreeNode T =  reBuild(inorder_array, preorder_array, 0, 5);
    inorder(T);
    System.out.print("\n");
    
  }
}
