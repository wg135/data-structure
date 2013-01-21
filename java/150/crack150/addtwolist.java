//add to linked list
import chapter2.*;

public class addtwolist{

  public static ListNode add(ListNode l1, ListNode l2){
     if((l1 == null) && (l2 == null))
	return null;
     ListNode result = null;
     int carry = 0;
	
     while((l1 != null) || (l2 !=null) || (carry != 0)){
	int value = 0;
	if(l1 != null){
	  value += l1.data;
	  l1 = l1.next;
	}
	if(l2 != null){
	  value += l2.data;
	  l2 = l2.next;
	}
        if(carry != 0)
	  value += carry;
	if(result == null)
	  result = new ListNode(value % 10);
	else
	  result.addtoend(value % 10);
        if(value >= 10)
	  carry = 1;
 	else
	  carry = 0;  	  
     }	
    
     return result;		
  }    
	
   public static void main(String[] args){
      int[] arr1 = {1, 6};
      int[] arr2 = {9, 2};

      ListNode list1 = new ListNode(7);
      for(int data: arr1)
        list1.addtoend(data);

      ListNode list2 = new ListNode(5);
      for(int data: arr2)
        list2.addtoend(data);
       ListNode result = add(list1, list2);
 	while(result != null){
	  System.out.printf("%d ", result.data);
	  result = result.next;	
	}	
	System.out.printf("\n");
  }
}
