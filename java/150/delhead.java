import chapter2.*;

public class delhead{

  public static ListNode nexthead(ListNode T){
    if(T.next == null)
      return null;
    else{
      T = T.next;
    }
    return T;
  }


  public static void main(String[] args){

    ListNode listA = new ListNode(10);
    listA.addtoend(15);
    listA.addtoend(4);
    listA.addtoend(20);
    
    ListNode b = nexthead(listA);
    while(b != null){
      System.out.printf("%d ", b.data);
      b = b.next;
    }
    System.out.print("\n");
  }
} 
