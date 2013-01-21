public abstract class animal{

  private int order;
  protected String name;
  
  public animal(String n){
	name = n;
  }    
  
  public void setorder(int count){
	order = count;
  }

  public int getorder(){
	return order;
  }
  
  public boolean olderthan(animal a){
	return this.order < a.order;
  }	
}

public class dog extends animal{

  public dog(String n){
	super(n);
  }
}

public class cat extends animal{

  public cat(String n){
	super(n);
  }
}

public class shelter{

  LinkedList<dog> d = new LinkedList<dog>();
  LinkedList<cat> c = new LinkedList<cat>();
  private int order = 0;

  public void enqueue(animal a){
	a.setorder(order);
	order++;
 	if(instance is dog)
	  d.addLast(a);
	else
  	  c.addLast(a);
  }

  public animal dequeue(){
	if(d.size() == 0)
	  return dequeuecat();
	else if(c.size() == 0)
	  return dequeuedog();
     	
	dog dogs = d.peek();
	cat cats = c.peek();
  
	if(dogs.olderthan(cats))
	  return dequeuecat();
	else
	  return dequeuedog();
  }

  public dog dequeuedog(){
	return d.poll();
  }

  public cat dequeuecat(){
	return c.poll();
  }

}

