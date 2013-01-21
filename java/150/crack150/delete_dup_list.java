
import chapter2.*;
import java.util.*;

public class delete_dup_list{

  public static void delete_dup(ListNode L){
	if((L == null) || (L.next == null))
	  return;
	Hashtable table = new Hashtable();
	ListNode p1 = L;
	table.put(p1.data, true);
	ListNode p2 = p1.next;

	while(p2 != null){
	  if(table.containsKey(p2.data)){
	    p1.next = p2.next;
	    p2 = p1.next;
	  }
	  else{
	    table.put(p2.data, true);
	    p1 = p1.next;
	    p2 = p2.next;	
	  }
	}
  }
	
  public static void main(String[] args){
	int[] a = {1, 2, 3, 3, 4, 5, 6, 7, 7, 8};
	ListNode L = new ListNode(0);
	for(int data : a)
	  L.addtoend(data);
	delete_dup(L);
	ListNode p = L;
	while(p != null){
	  System.out.printf("%d ", p.data);
	  p = p.next;
  	}
	System.out.printf("\n");

  }
}
