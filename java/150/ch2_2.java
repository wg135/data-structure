import chapter2.*;
import java.util.*;

public class ch2_2{

  public static ListNode nth(ListNode list, int n){
    if((list == null)||(n < 1))
      return null;
    ListNode p1, p2;
    p1 = list;
    p2 = list;
    for(int i=n; i>0; i--){
      if(p2 = null)
        return null;
      else
         p2 = p2.next;
    }
    while(p2.next != null){
      p1 = p1.next;
      p2 = p2.next;
    }
    
     return p1; 
  }

  public static void main(String[] args){
    int array[] ={1, 2, 3, 4, 5, 6, 7, 7, 8, 9, 10};
    ListNode list = new ListNode(0);
    for(int data: array)
      list.addtoend(data);
    ListNode p = list;
    while(p != null){
      System.out.printf("%d ", p.data);
      p = p.next;
    }
    System.out.print("\n");
  }
}
