//min O(1) in stack
import java.util.*;

public class stack_min extends Stack<Integer>{
	Stack<Integer> s2;
	
	public stack_min(){
	  s2 = new Stack<integer>();
	}
  
	public void push(int data){
	  if(data <= min())
	    s2.push(data);
	  super.push(data);
	}

	public int pop(){
	  int value = super.pop();
	  if(value == min())
	    s2.pop();
	  return value;
	}
	
	public int min(){
	  if(s2.isEmpty())
	    return Integer.MAX_VALUE;
	  else
	    return s2.peek();
	}

  public static void main(String[] args){

  }
}
