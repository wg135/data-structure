import chapter2.*;

public class addlist{

  public static ListNode sum(ListNode list1, ListNode list2){
    if(list1 == null)
      return list2;
    if(list2 == null)
      return list1;
    int carry = 0;
    int sum;
    ListNode result = null;

    while(list1 != null || list2 != null){
      sum = (list1 != null ? list1.data : 0) + (list2 != null? list2.data : 0) + carry;
      if(sum >= 10)
        carry = 1;
      else
        carry = 0;

      sum = sum%10;    
      if(result == null)
        result = new ListNode(sum);
      else
        result.addtoend(sum);        
     if(list1 != null)
       list1 = list1.next;
     if(list2 != null)
       list2 = list2.next;      
    }
    
    return result; 
  }

  public static void main(String[] args){
    ListNode list1 = new ListNode(7);
    list1.addtoend(5);
    list1.addtoend(9);
    list1.addtoend(4);
    list1.addtoend(6);
    
    ListNode list2 = new ListNode(8);
    list2.addtoend(4);
    ListNode result = sum(list1, list2);
    while(result != null){
      System.out.printf("%d ", result.data);
      result = result.next;
    } 
  }
}
