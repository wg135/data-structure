import chapter2.*;
import java.util.*;

public class ch2_3{

  public static void change(ListNode list){
    if(list == null)
      return;
    list.data = list.next.data;
    list.next = list.next.next;
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
    p = list;
    for(int i=5; i>=0; i--)
     p = p.next;
     change(p);
    while(list != null){
      System.out.printf("%d ", list.data);
      list = list.next;
    }

    System.out.print("\n");
  }
}
