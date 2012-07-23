/*Given a Binary Tree, find the maximum sum path from a leaf to root
*/


public class maxiumpath{

  static int maxleaf = Integer.MIN_VALUE;
  static TreeNode leaf = null;

  public static boolean printpath(TreeNode root, TreeNode leaf){
    if(root == null)
     return false;

    if((root == leaf)||printpath(root.left, leaf)||printpath(root.right, leaf)){
      System.out.printf("%d ", root.data);
      return true;
  }
    return false; 
  }

  public static void getleaf(TreeNode root, TreeNode leaf, int curr){
    if(root == null)
      return;

    curr = curr + root.data;
     
    if((root.left == null)&&(root.right == null)){
      if(maxleaf < curr){
        maxleaf = curr;
        leaf = root;
      }
    } 
    getleaf(root.left, leaf, curr);
    getleaf(root.right, leaf, curr);
  }

  public static int maxpath(TreeNode T){
    if(T == null)
      return 0;
    getleaf(T, leaf, 0);
    printpath(T, leaf);
    System.out.print("\n"); 
    return maxleaf;
  }

  public static void main(String[] args){
    TreeNode T = new TreeNode(10);
    T.left = new TreeNode(-2);
    T.right = new TreeNode(7);
    T.left.left = new TreeNode(8);
    T.left.right = new TreeNode(-4);
    int sum = maxpath(T); 
    System.out.printf("%d\n", sum);
  }
}

