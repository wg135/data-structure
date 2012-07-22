/*Given Inorder Traversal of a Special Binary Tree 
in which key of every node is greater than keys 
in left and right children, 
construct the Binary Tree and return root.
*/


public class specialbinary{

  public static TreeNode build(int[] a, int start, int end){
  int i;
  
  if(start > end)
      return null;
  
  i = max(a, start, end);
  TreeNode T = new TreeNode(a[i]);
  
  if(start == end)
    return T;

  T.left = build(a, start, i-1);
  T.right = build(a, i+1, end); 
    
  return T;
  }

  public static int max(int[] a, int start, int end){
    int value = Integer.MIN_VALUE;
    int i;
    for(i=start; i<end; i++){
      if(value < a[i])
        value = a[i];
    } 
    return i;
  }
  
  public static void inorder(TreeNode T){
    if(T == null)
      return;
    inorder(T.left);
    System.out.printf("%d ", T.data);
    inorder(T.right);
  }
 
  public static void main(String[] args){
    int[] a = {5, 10, 40, 30, 28};
    TreeNode T = build(a, 0, a.length-1);
    inorder(T);
    System.out.print("\n");
  }
}
