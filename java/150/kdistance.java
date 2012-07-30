/*
*/

public class kdistance{

  public static void print(TreeNode T, int k){
    if(T == null)
      return;
    if(k==0){
      System.out.printf("%d ", T.data);  
      return;
    }
    else{
      print(T.left, k-1);
      print(T.right, k-1);
    }
  }
  public static void main(String[] args){
    TreeNode T = new TreeNode(1);
    T.left = new TreeNode(2);
    T.right = new TreeNode(3);
    T.left.left = new TreeNode(4);
    T.left.right = new TreeNode(5);
    T.right.left = new TreeNode(8);
    print(T, 2);
    System.out.printf("\n");
  }
}
