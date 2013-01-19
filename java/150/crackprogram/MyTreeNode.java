import java.util.*;

public class MyTreeNode{
  
  MyTreeNode left;
  int data;
  MyTreeNode right;

  public MyTreeNode(int value){
    data = value;
    left = null;
    right = null;
  }
  
  public void insert(int value){
    if(value < data){
      if(left == null)
        left = new MyTreeNode(value);
      else
        left.insert(value);
    }
   else if(value > data){
     if(right == null)
       right = new MyTreeNode(value);
     else
       right.insert(value);
   }
  }

  public void pre_order(){
	System.out.printf("%d ", data);
	if(left != null)
	  left.pre_order();
	if(right != null)
	  right.pre_order();
  }

  public void in_order(){
	if(left != null)
	  left.in_order();
	System.out.printf("%d ", data);
	if(right != null)
	  right.in_order();
  }

  public void post_order(){
	if(left != null)
	  left.post_order();
 	if(right != null)
	  right.post_order();
	System.out.printf("%d ", data);
  }

  public void in_order_stack(){
	Stack<MyTreeNode> stack = new Stack<MyTreeNode>();
	
	MyTreeNode current = this;
	
      	while((current != null) || (!stack.isEmpty())){
	  if(current != null){
		stack.push(current);
		current = current.left;		
	  }
	  else{
	    	current = stack.pop();
		System.out.printf("%d ", current.data);
		current = current.right;
	  }
 	}
  }

  public void pre_order_stack(){
	Stack<MyTreeNode> stack = new Stack<MyTreeNode>();
	
	MyTreeNode current = this;

	while((current != null) || (!stack.isEmpty())){
	  if(current != null){
		System.out.printf("%d ", current.data);
		stack.push(current.right);
	  	current = current.left;
	  }	
	  else
		current = stack.pop();
	}
  }

  public void post_order_stack(){
	Stack<MyTreeNode> stack = new Stack<MyTreeNode>();
	
	MyTreeNode current = this;
	
  }
  
}
