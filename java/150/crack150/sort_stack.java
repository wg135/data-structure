//sort the stack
import java.util.*;

public class sort_stack{

  public static void sort(Stack<Integer> stack){
	Stack<Integer> r = new Stack<Integer>();
	int tmp = 0;
	while(!stack.isEmpty()){
	  tmp = stack.pop();
	  while(!r.isEmpty() && (r.peek() < tmp))
	    stack.push(r.pop());

	  r.push(tmp);
        }        	
	while(!r.isEmpty())
	   stack.push(r.pop());
  }

  public static void main(String[] args){
    Stack<Integer> stack = new Stack<Integer>();
    stack.push(2);
    stack.push(5);
    stack.push(4);
    stack.push(3); 
	
    sort(stack);
    while(!stack.isEmpty())
	System.out.printf("%d\n", stack.pop());
  }
}
