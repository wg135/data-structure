//Find Intersection of Two Lists
import chapter2.*;

public class ListIntersection{

  public static boolean intersection(ListNode L1, ListNode L2){
	ListNode tail_l1 = L1;
	if(L1 == null)
	  return false;  //l1 is empty so no intersection
	while(tail_l1.next != null)
	  tail_l1 = tail_l1.next; //get the tail of L1

        tail_l1.next = L2; // connect the tail of l1 and head of l2

	ListNode slow = L1;
	ListNode fast = L1.next;
   
	while((slow != null) && (fast != null)){
		if(slow == fast)
		  return true;
	        slow = slow.next;
	 	fast = fast.next;
		if(fast != null)
		  fast = fast.next;
	}

	return false;
  }

  public static void main(String[] args){
	ListNode L1 = new ListNode(1);	
    	L1.addtoend(3);
	L1.addtoend(5);
	L1.addtoend(7);
	L1.addtoend(9);

	ListNode L2 = new ListNode(2);
	L2.addtoend(4);
        
	ListNode tmp = L1.next.next;
	L2.next.next = tmp;
       
	if(intersection(L1, L2))
	  System.out.printf("yes\n");
      
  }
}
