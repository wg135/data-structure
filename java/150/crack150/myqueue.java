
public class myqueue{
  
	public Stack<Integer> stack_old;
	public Stack<Integer> stack_new;
	
	public myqueue(){
	  stack_old = new Stack<Integer>();
	  stack_new = new Stack<Integer>();
	}

	public void enqueue(int v){
	  stack_old.push(v);
	}

	public int dequeue(){
	  if(stack_new.isEmpty()){
	    while(!stack_old.isEmpty()){
	      stack_new.push(stack_old.pop());
	    }  
	  }
	  return stack_new.pop();
	}
	
	public int size(){
	  return stack_old.size() + stack_new.size();
	}

	
}
