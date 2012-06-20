import java.util.*;

public class ch3_6{

  public static Stack<Integer> sort(Stack<Integer> s){
    Stack<Integer> r = new Stack<Integer>();
    int tmp;
    while(!s.empty()){
      tmp = s.pop();
     while((!r.empty())&&(tmp < r.peek())){
         s.push(r.pop());
      }
      r.push(tmp); 
      
    }   
   
    while(!r.empty())
      s.push(r.pop()); 
    
    return s;
  }

  public static void main(String[] args){
    Stack<Integer> s = new Stack<Integer>();
    Stack<Integer> r = new Stack<Integer>();
    s.push(2);
    s.push(3);
    s.push(1);
    s.push(4);
    r = sort(s);
    for(int i=0; i<4; i++)
      System.out.println(r.pop());
    
  }
}
