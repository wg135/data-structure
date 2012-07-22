/*Given a Binary Tree, convert it to a Binary Search Tree. 
The conversion must be done in such a way that keeps the 
original structure of Binary Tree
*/

import java.util.*;

public class bt2bst1{

  static int index = 0;
  static int index1 = 0;

  public static int count(TreeNode T){
    if(T == null)
      return 0;
    else
     return count(T.left) + count(T.right) + 1;
  }
 
  public static void store2array(TreeNode T, int[] a){
    if(T == null)
      return;
     
    store2array(T.left, a);
    a[index++] = T.data;
    store2array(T.right, a);
   
  }

  public static void write2bt(TreeNode T, int[] a){
    if(T == null)
      return;
    write2bt(T.left, a);
    T.data = a[index1++];
    write2bt(T.right, a);
  }

  public static TreeNode bt2binarysearch(TreeNode T){
    
    int len;
    TreeNode node;
    
    node = T; 
    len = count(T);
    int[] a = new int[len];
    store2array(node, a);
    Arrays.sort(a);
    write2bt(node, a); 
   
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

    TreeNode result;
    TreeNode T = new TreeNode(10);
    T.left = new TreeNode(2);
    T.right = new TreeNode(7);
    T.left.left = new TreeNode(8);
    T.left.right = new TreeNode(4);
   
    result = bt2binarysearch(T);
    inorder(result);
    System.out.print("\n");
  }
}
