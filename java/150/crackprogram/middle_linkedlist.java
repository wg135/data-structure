//Find List Mid Point in linked list 
import chapter2.*;

public class middle_linkedlist{

  public static ListNode middle_point(ListNode L){
 
	if((L == null) || (L.next == null)) //list is empty or only one element
	  return L;

	ListNode slow = L;
	ListNode fast = L;

	while(fast != null){
	  slow = slow.next;
	  fast = fast.next;
	  if(fast != null)
	    fast = fast.next;
	}

	return slow;	 
  }

  public static void main(String[] args){
	ListNode list = new ListNode(0);
	for(int i=1; i<10; i++){
	   list.addtoend(i);
        }
	
 	ListNode  tmp = middle_point(list);
	System.out.printf("%d\n", tmp.data);	
  }
}
