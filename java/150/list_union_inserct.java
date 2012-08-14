/*Given two Linked Lists, 
create union and intersection lists that contain 
union and intersection of the elements present in the given lists. 
Order of elments in output lists doesn’t matter
*/
import chapter2.*;
import java.util.*;

public class list_union_inserct{

  public static boolean isnotin(ListNode n, int value){
    if(n == null)
      return false;
    ListNode tmp = n;
    while(tmp != null){
      if(tmp.data == value)
       return false;
       tmp = tmp.next;
    }  
    return true;
  }
  public static ListNode getunion(ListNode A, ListNode B){
    if(A == null)
      return B;
    if(B == null)
      return A;
    ListNode a = A;
    ListNode b = B;
    ListNode C = new ListNode(a.data);
    a = a.next;
    while(a != null){
      C.addtoend(a.data);
      a = a.next;
    }
    while(b != null){
      if(isnotin(C, b.data))
       C.addtoend(b.data);
      b = b.next;
    }    
    return C;      
  }
 
 /* public static ListNode getinsert(ListNode A, ListNode B){
    ListNode a = A;
    ListNode b = B;
     
  }*/
 
  public static void main(String[] args){
    ListNode listA = new ListNode(10);
    ListNode listB = new ListNode(8);
    
   listA.addtoend(15);
   listA.addtoend(4);
   listA.addtoend(20);
   
   listB.addtoend(4);
   listB.addtoend(2);
   listB.addtoend(10);
   ListNode u = getunion(listA, listB);
   while(u != null){
     System.out.printf("%d ", u.data);
     u = u.next;
   }
   System.out.print("\n");
    
  }
}
