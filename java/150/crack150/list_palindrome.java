//check if a linked list is palindrome
import chapter2.*;
import java.util.*;

public class list_palindrome{

  public static boolean is_palindrome(ListNode L){
	ListNode slow = L;
	ListNode fast = L;
	
	Stack<ListNode> stack = new Stack<ListNode>();
	while((fast != null) && (fast.next != null)){
	   stack.push(slow);
	   slow = slow.next;
	   fast = fast.next.next;
	}	
	slow = slow.next; //skip the middle one;
	
	while(slow != null){
	  int value = stack.pop().data;
	  if(value != slow.data)
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

     if(is_palindrome(list))	
	System.out.println("yes");	
  }
}

