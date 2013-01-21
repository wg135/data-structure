//find the kth to the last element of a linked list
import chapter2.*;

public class kth_to_end_list{

  public static ListNode kth(ListNode L, int k){
	if(L == null)
	  return null;
	ListNode slow = L;
	ListNode fast = L;

	for(int i=k; i>0; i--){
	   if(fast != null)
	     fast = fast.next;
	}
	
	while(fast != null){
	  fast = fast.next;
	  slow = slow.next;
	}

	return slow;	  
  }
		
  public static void main(String[] args){

	int[] a = {1, 2, 3, 3, 4, 5, 6, 7, 7, 8};
        ListNode L = new ListNode(0);
        for(int data : a)
          L.addtoend(data);
	System.out.printf("%d\n", kth(L, 2).data);
  }

}
