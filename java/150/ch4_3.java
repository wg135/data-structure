import java.util.*;

class ch4_3{

  public static TreeNode bt(int array[], int start, int end){
    if(start > end)
      return null;
    int middle = start + (end - start)/2;
    TreeNode t = new TreeNode(array[middle]);
    t.left = bt(array, start, middle-1);
    t.right = bt(array, middle+1, end);
   
    return t; 
  }
  
  public static TreeNode creat(int array[]){
    return bt(array, 0, array.length -1);
  }
  
  public static void inorder(TreeNode T){
    if(T == null)
      return;
    inorder(T.left);
    System.out.printf("%d ", T.data);
    inorder(T.right);
  }
    
  public static void main(String[] args){
    int[] array = new int[10];
    int i;
    TreeNode T = null;
    for(i=0; i<10; i++)
      array[i] = i;

    T = creat(array);
    inorder(T);
    System.out.print("\n");
  }
  
}

