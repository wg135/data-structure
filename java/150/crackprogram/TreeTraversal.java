
public class TreeTraversal{

  
  public static void main(String[] args){

	MyTreeNode T = new MyTreeNode(5);
        T.insert(3);
        T.insert(2);
        T.insert(4);
        T.insert(6);

	T.pre_order();
	System.out.printf("\n");
	T.pre_order_stack();
	System.out.printf("\n");
	T.in_order();
	System.out.printf("\n");
	T.in_order_stack();
	System.out.printf("\n");
	T.post_order();
	System.out.printf("\n");

  }
}
