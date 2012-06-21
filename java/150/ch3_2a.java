import java.util.*;

public class ch3_2a{
  Stack<Integer> s1, s_add;

  public ch3_2a(){
    s1 = new Stack<Integer>();
    s_add = new Stack<Integer>();
  } 
 
  public void Push(int data){
    s1.push(data);
    if(data > min())
      s_add.push(min());
    else
      s_add.push(data);
  }
  
  public int Pop(){
    s_add.pop();
    return s1.pop();
  }
  
  public int min(){
    if(s_add.empty())
      return Integer.MAX_VALUE;
    else
      return s_add.peek();
  } 

  public static void main(String[] args){
    ch3_2a stack = new ch3_2a();
    int[] array = {4, 2, 1, 3};
    int i;
    for(i=0; i< 4; i++)
      stack.Push(array[i]);
    
    System.out.println(stack.min());
   
  }
}
