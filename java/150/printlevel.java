//Print all nodes of a binary tree at a certain level 
public class printlevel{

  public static void print_re(TreeNode T, int current, int desire){
    if(T == null || current > desire)
	return;
    if(current == desire)
	System.out.print(T.data + " ");
    else{
      print_re(T.left, current+1, desire);
      print_re(T.right, current+1, desire);
    }
  }

  public static void main(String[] args){

    TreeNode T = new TreeNode(5);
    T.insert(3);
    T.insert(7);
    T.insert(2);
    T.insert(4);
    T.insert(6);
    print_re(T, 0, 2);
    System.out.printf("\n");
  }
}
