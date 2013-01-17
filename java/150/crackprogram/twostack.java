//Use Stack To Simulate Queuey
import java.util*;

public class twostack{

	Stack<int> stack_old, stack_new;

        public twostack(){
	  stack_old = new Stack<int>();
	  stack_new = new Stack<int>();
	}
      
	public int size(){
	  return stack_old.size() + stack_new.size();
	}

	public void enqueue(int k){
		stack_new.push(k);
	}
	
	public int dequeue(){
		if(stack_old.isempty()){
			while(!stack_new.isempty())
				stack_old.push(stack_new.pop());
		}
		return stack_old.pop();
			
	}
}
