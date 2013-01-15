import chapter2.*;
import java.util.*;

public class ch2_1{
 
    public static void del_dup(ListNode list){
      Hashtable map = new Hashtable();
      ListNode p1 = list;
      if(p1 == null)
        return;
      ListNode p2 = list.next;
      map.put(p1.data, true);
      while(p2 != null){
       if(map.containsKey(p2.data)){
         p1.next = p2.next;
         p2 = p1.next; 
       }
       else{
         map.put(p2.data, true);
         p1 = p1.next;
         p2 = p2.next; 
       }
      }
    } 

    public static void main(String[] args){
      int array[] = {1, 2, 3, 3, 4, 5, 6, 7, 7, 8, 9, 10};
      ListNode list = new ListNode(0);
      for(int data: array)
         list.addtoend(data);   
      ListNode p = list; 
      while(p != null){
        System.out.printf("%d ", p.data);
        p = p.next;
      } 
      System.out.print("\n");
      del_dup(list);
      while(list != null){
        System.out.printf("%d ", list.data);
        list = list.next;
      }
      System.out.print("\n");

    }
}
