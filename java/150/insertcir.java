import chapter2.*;

public class insertcir{
  
  public static void insertion(ListNode head, int value){
    ListNode tmp = head;
    if(head == null){
      head = new ListNode(value);
      head.next = head;
    } 
   if(tmp.data >= value){
     while(tmp.next != head)
       tmp = tmp.next;
     tmp.next = new ListNode(value);
     tmp = tmp.next;
     tmp.next = head;
     head = tmp;
   }
   else{
     while(tmp.next != head && tmp.next.data < value)
       tmp = tmp.next;
     ListNode curr = new ListNode(value);
     curr.next = tmp.next;
     tmp.next = curr;
   } 
  }

  public static void main(String[] args){
    ListNode list = new ListNode(2);
    list.addtoend(11);
    list.addtoend(12);
    list.addtoend(56);
    list.addtoend(90);
    ListNode head = list;
    ListNode tmp = list;
   
   while(tmp.next != null)
     tmp = tmp.next;        
   tmp.next = list;
   insertion(head, 1); 
  }
}
