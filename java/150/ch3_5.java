import java.util.*;

public class ch3_5<Object>{

  Stack<Object> s1, s2;

  public ch3_5(){
    s1 = new Stack<Object>();
    s2 = new Stack<Object>();
  }

  public int size(){
    int size = s1.size() + s2.size();
  
    return size;
  } 
  public void enqueue(Object data){
    s1.push(data);
  }

  public  Object peek(){
    if(!s2.empty())
      return s2.peek();
    while(!s1.empty())
      s2.push(s1.pop());
    return s2.peek();
  }
 
  public Object dequeue(){
    if(!s2.empty())
     return s2.pop();
    while(!s1.empty())
     s2.push(s1.pop());
    return s2.pop();
  }

  public static void main(String[] args){
    int i;
    ch3_5 queue = new ch3_5();
    for(i=0; i<5; i++)
      queue.enqueue(i);
    for(i=0; i<5; i++)
      System.out.println(queue.dequeue());
  } 
}
