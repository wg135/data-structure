//delete the middle element of linked list
import chapter2.*;
public class delete_middle_list{

  public static void delet_midd(ListNode p){
    if((p == null) || (p.next == null))
	return;
        p.data = p.next.data;
	p.next = p.next.next;	
  }  

  public static void main(String[] args){
	ListNode L = new ListNode('a');
	L.addtoend('b');
	L.addtoend('c');
	L.addtoend('d');
	L.addtoend('e');
       
	ListNode p = L.next.next;
	delet_midd(p);
	while(L != null){
	  System.out.printf("%c ", L.data);
	  L = L.next;
	}
	System.out.printf("\n");
  }
}
