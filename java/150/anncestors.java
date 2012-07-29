/*Given a Binary Tree and a key, write a function that prints all the ancestors of the key in the given binary tree. 
*/

public class anncestors{

  public static boolean print(TreeNode T, int key){
    if(T == null)
      return true;

    if(T.data == key)
      return true;
  
    if(print(T.left, key)||print(T.right, key)){
      System.out.printf("%d ", T.data);
      return true;
    }
    return false;
  }
  public static void main(String[] args){
    TreeNode T = new TreeNode(1);
    T.left = new TreeNode(2);
    T.right = new TreeNode(3);
    T.left.left = new TreeNode(4);
    T.left.right = new TreeNode(5);
    T.left.left.left = new TreeNode(7);
    print(T, 7);
    System.out.print("\n");
  }
}
