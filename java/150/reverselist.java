import chapter2.*;
public class  reverselist{

  public static ListNode reverse(ListNode L){
    if((L == null)||(L.next == null))
      return L;
    ListNode curr = L;
    ListNode prev = null;
    ListNode nex;
    
    while(curr != null){
      nex = curr.next;
      curr.next = prev;
      prev = curr;
      curr = nex;
    }
    return prev;
  }  
  public static void main(String[] args){
    ListNode L = new ListNode(0);
    ListNode tmp = L;
    for(int i=1; i<10; i++)
      tmp.addtoend(i);
    while(tmp != null){
      System.out.printf("%d ", tmp.data);
      tmp = tmp.next;
    }
    System.out.printf("\n");
   
    ListNode p = reverse(L);
    while(p != null){
      System.out.printf("%d ", p.data);
      p = p.next;
    } 
    System.out.printf("\n");
  }
}
