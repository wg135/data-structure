
import java.util.*;

  public class setofstacks{
	ArrayList<Stack> stacks = new ArrayList<Stack>();
	public int capacity;

	public setofstacks(int capacity){
	  this.capacity = capacity;
	}		

	public Stack getlaststack(){
	  if(stacks.size() == 0)
	    return null;
	  else
	    return stacks.get(stacks.size() - 1);
	}	

	public void push(int v){
	  Stack last = getlaststack();
	  if(last != null && !last.isFull())
	    last.push(v);
	  else{
	    Stack stack = new Stack(capacity);
	    stack.push(v);
	    stacks.add(stack);
	  }
	}

	public int pop(){
	  Stack last = getlaststack();
	  int v = last.pop()
	  if(last.size == 0)
	    stacks.remove(stacks.size() - 1);
	    return v;
	  
	}
}
