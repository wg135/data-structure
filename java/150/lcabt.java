public class lcabt{

  public static TreeNode find(TreeNode T, TreeNode t1, TreeNode t2){
    if(T == null)
      return null;
    if((T == t1)||(T == t2))
      return T;

    TreeNode L = find(T.left, t1, t2);
    TreeNode R = find(T.right, t1, t2);
    if((L != null)&&(R != null))
      return T;
   
     if(L != null)
       return L;
     else
       return R;
  }

  public static void main(String[] args){
    TreeNode T = new TreeNode(5);
    T.insert(3);
    T.insert(7);
    T.insert(2);
    T.insert(4);
    T.insert(6);
    System.out.printf("%d\n", find(T, T.left, T.right).data);
  }
}
