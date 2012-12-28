import chapter2.*;
import java.util.*;

public class ch2_7{

  public static boolean parlindromic(ListNode list){
    ListNode slow = list;
    ListNode fast = list;
    
    Stack<Integer> stack = new Stack<Integer>();

    while((fast != null)&&(fast.next != null)){
      stack.push(slow.data);
      fast = fast.next.next;
      slow = slow.next;
    }

    if(fast != null)
      slow = slow.next;

    while(slow != null){
      int top = stack.pop().intValue();
      if(slow.data != top)
        return false;

      slow = slow.next; 
    } 
    return true;
  }

  public static void main(String[] args){
    int array[] = {2, 3, 4, 5, 4, 3, 2, 1};
    ListNode list = new ListNode(1);
    for(int data: array)
      list.addtoend(data);
   
     if(parlindromic(list)) 
      System.out.println("yes");
  } 
}
