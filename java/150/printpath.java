

public class printpath{
  
  public static void print(TreeNode T){
    int[] path = new int[10];
    printutil(T, path, 0);
  }

  public static void printutil(TreeNode T, int[] path, int len){
    
    if(T == null)
      return;

    path[len] = T.data;
    len++;
  
    if((T.left == null)&&(T.right ==null))
      printarray(path, len);
    else{
      printutil(T.left, path, len);
      printutil(T.right, path, len);
    }
  }
  
  public static  void printarray(int[] path, int len){
    int i;
    for(i=0; i<len; i++){
      System.out.printf("%d ", path[i]);
    }
    System.out.print("\n");
  }
  public static void main(String[] args){
    TreeNode T = new TreeNode(10);
    T.left = new TreeNode(8);
    T.right = new TreeNode(2);
    T.left.left = new TreeNode(3); 
    T.left.right = new TreeNode(5);
    T.right.left = new TreeNode(2);

    print(T);
  }
}
