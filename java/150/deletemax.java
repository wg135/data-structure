import chapter2.*; 

public class deletemax{
 
  public static ListNode reverse(ListNode list){
    ListNode current = list;
    ListNode prev = null;
    ListNode next;

    while(current != null){
      next = current.next;
      current.next = prev;
      prev = current;
      current = next;
    }
    return prev;
  }
 
  public static void deleteless(ListNode list){
    ListNode tmp = list;
    if(tmp == null)
      return;
    int max = tmp.data;
    while((tmp != null)&&(tmp.next != null)){
      if(max > tmp.next.data){
        tmp.next = tmp.next.next;
      }
      else{
         max = tmp.next.data;
         tmp = tmp.next;
      }
    }
    
  }
  public static void main(String[] args){
    ListNode list = new ListNode(12);
    int array[] = {15, 10, 11, 5, 6, 2, 3}; 
    for(int data: array)
      list.addtoend(data);
    ListNode tmp = list;
    while(tmp != null){
      System.out.printf("%d ", tmp.data);
      tmp = tmp.next;
    }
    System.out.print("\n");
    tmp = reverse(list);
  deleteless(tmp);
  ListNode temp = reverse(tmp);
  while(temp != null){
      System.out.printf("%d ", temp.data);
      temp = temp.next;
    }
    System.out.print("\n");
  }
} 
