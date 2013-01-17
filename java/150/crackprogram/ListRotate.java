//Rotate Linked List
import chapter2.*;
public class ListRotate{

  public static ListNode rotate(ListNode L, int k){
	ListNode result = null;
	ListNode tmp = L;
        while(k>2){  //step1: find the new head
 	  if(tmp != null){
	    tmp = tmp.next;
            k--;
          }
        }
        if(tmp.next != null) 
	  result = tmp.next;	

        tmp.next = null; //step2: set the new tail
        ListNode nex = result;
	while(nex.next != null) //step3: connect the old head
	  nex = nex.next;
        
       nex.next = L;
   
      return result;
	
  }

  public static void main(String[] args){
	ListNode L = new ListNode(1);
	for(int i=2; i<=10; i++)
	  L.addtoend(i);

        ListNode list = rotate(L, 4);
        while(list != null){
	  System.out.printf("%d ", list.data);
          list = list.next;
        }

	System.out.printf("\n");
  }
} 
