/*
Given two values k1 and k2 (where k1 < k2) and a root pointer to a Binary Search Tree. Print all the keys of tree in range k1 to k2. i.e. print all x such that k1<=x<=k2 and x is a key of given BST. Print all the keys in increasing order. 
*/

public class printbst{

  public static void print(TreeNode T, int k1, int k2){
    if(T == null)
      return;

    if(k1 < T.data)
      print(T.left, k1, k2);

    if((k1<= T.data)&&(k2 >= T.data))
      System.out.printf("%d ", T.data);
   
    if(k2 > T.data)
      print(T.right, k1, k2); 
  }

  public static void main(String[] args){
    TreeNode T = new TreeNode(20);
    T.left = new TreeNode(8);
    T.right = new TreeNode(22);
    T.left.left = new TreeNode(4);
    T.left.right = new TreeNode(12);
    print(T, 10, 22);
    System.out.print("\n");
  }

}
