import java.util.*;

public class bt2bst{

  static int index = 0;
  static int index1 = 0;
  public static TreeNode tobst(TreeNode T){
    int len;
    TreeNode node;
    
    len = countnode(T);
    int[] array = new int[len];
    node = T;
    
   storeinorder(node, array);
  /*   for(int i=0; i<len; i++)
    System.out.printf("%d ", array[i]);
   System.out.print("\n"); */
   Arrays.sort(array);

   copyinorder(node, array); 
  
   return T;
  }

  public static int countnode(TreeNode T){
    TreeNode node = T;
    if(T == null)
      return 0;
    return countnode(T.left) + countnode(T.right) + 1;
  }

  public static void copyinorder(TreeNode T, int[] array){
    if(T == null)
      return;
    copyinorder(T.left, array);
    T.data = array[index1++];
    copyinorder(T.right, array);
    
  }

  public static void storeinorder(TreeNode T, int[] array){
   if(T == null)
     return;
  
   storeinorder(T.left, array);
   array[index++] = T.data;
   storeinorder(T.right, array);
  }

  public static void inorder(TreeNode T){
    if(T == null)
      return;
    inorder(T.left);
    System.out.printf("%d ", T.data);
    inorder(T.right);
  }

  public static void main(String[] args){
    TreeNode T = new TreeNode(5);
    T.insert(3);
    T.insert(7);
    T.insert(2);
    T.insert(4);
    T.insert(6);
    
    TreeNode result;

    result = tobst(T);
    inorder(result);

    System.out.print("\n"); 
  }
}
