/*
Given a sorted array. Write a function that creates a Balanced Binary Search Tree using array elements
*/

public class array2bst{

  public static TreeNode build(int[] a, int start, int end){
    if(start > end)
      return null;
    int mid = start + (end - start)/2;
    TreeNode T = new TreeNode(a[mid]);
    T.left = build(a, start, mid-1);
    T.right = build(a, mid+1, end);

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
    int[] a = {1, 2, 3, 4, 5};
    TreeNode T = build(a, 0, a.length-1);
    inorder(T);
    System.out.print("\n");
  }
}
