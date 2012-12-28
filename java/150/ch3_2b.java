import java.util.*;

public class ch3_2b extends Stack<Integer>{
    
    Stack <Integer> s_add;
    public ch3_2b(){
      s_add = new Stack<Integer>();
    }
    
    public void push(int data){
      super.push(data);
      if(data < min())
        s_add.push(data);

    }

    public Integer pop(){
      int value = super.pop();
      if(value == min())
        s_add.pop();
      return value;
    }

   public int min(){
     if(s_add.empty())
       return Integer.MAX_VALUE;
     else
       return s_add.peek();
   }
  
   public static void main(String[] args){
      ch3_2b stack = new ch3_2b();
      int[] array = {4, 2, 1, 3};
      for(int data:array)
        stack.push(data);
     
      System.out.println(stack.min());
   }
}
