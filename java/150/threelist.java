import chapter2.*;
import java.util.*;

public class threelist{

  public static boolean sum(ListNode A, ListNode B, ListNode C, int num){
   
   ListNode a = A;
   while(a != null){
    ListNode b = B;
    ListNode c = C;
   
    while((b!= null)&&(c!= null)){
      int sum = a.data+b.data+c.data;
      if(sum == num){
        System.out.printf("%d + %d + %d = %d\n", a.data, b.data, c.data, num);
        return true;
      }
      if(sum < num)
        b = b.next;
      else
        c = c.next;
    }
    a = a.next;    
   }
   return false; 
  }

  public static void main(String[] args){
    ListNode listA = new ListNode(10);
    ListNode listB = new ListNode(2);
    ListNode listC = new ListNode(8);
    
    listA.addtoend(15);
    listA.addtoend(5);
    listA.addtoend(20);
   
    listB.addtoend(4);
    listB.addtoend(9);
    listB.addtoend(10);
  
    listC.addtoend(4);
    listC.addtoend(2);
    listC.addtoend(1);  
    sum(listA, listB, listC, 25); 
  }
}
