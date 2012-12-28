import chapter2.*;
import java.util.*;

public class ch2_5{

  public static boolean hasloop(ListNode head){
    if(head == null)
      return false;
    if(head.next == null)
      return false;

    ListNode slow = head;
    ListNode fast = head.next;
   
    while((slow != null)&&(fast != null)){
      if(slow == fast)
        return true;
      slow = slow.next;
      fast = fast.next;
      if(fast != null)
        fast = fast.next; 
    }
    return false;
  }

  public static ListNode findstart(ListNode head){
     ListNode slow = head;
     ListNode fast = head;
   
     while((fast != null)&&(fast.next != null)){
      slow = slow.next;
      fast = fast.next.next;
      if(fast == slow)
         break;
     } 
     if((fast == null)||(fast.next == null))
       return null;

      slow = head;
      while(slow != fast){
        slow = slow.next;
        fast = fast.next;
      }
      return slow;
  }

  public static void main(String[] args){
    int array[] ={1, 2, 3, 4, 5, 6, 7, 8, 9};
    ListNode list = new ListNode(0);
    for(int data: array)
      list.addtoend(data);
    ListNode tmp = list;
    tmp = tmp.next;
    tmp = tmp.next;
    ListNode p = list;
    while(p.next != null)
      p = p.next;
    p.next = tmp;
    
    if(hasloop(list))
      System.out.println("has loop");
    System.out.printf("%d\n", findstart(list).data); 
  }
}
