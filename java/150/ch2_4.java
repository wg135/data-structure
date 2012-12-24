import chapter2.*;

public class ch2_4{

  public static ListNode part(ListNode list, int k){

    ListNode small = null;
    ListNode small_tmp = null;
    ListNode great = null;
    ListNode great_tmp = null;
    ListNode tmp = list;
  
    while(tmp != null){
      if(tmp.data < k){
        if(small == null){
   	  small = new ListNode(tmp.data);
          small_tmp = small;
         }
         else{
	  small.addtoend(tmp.data);
          small_tmp = small_tmp.next;
         }
      }
      else{
        if(great == null){
	  great = new ListNode(tmp.data);
          great_tmp = great;
        }
        else{
	  great.addtoend(tmp.data);
          great_tmp = great_tmp.next;
        }
      }
      tmp = tmp.next;
    }
    small_tmp.next = great;

    return small;
    
    
  }
  
  public static void main(String[] args){
    
    int array[] = {1, 10, 3, 8, 6, 12, 2, 50, 3};
    ListNode list = new ListNode(19);
    for(int data: array)
      list.addtoend(data);
    ListNode p = list;
    
    while(p != null){
      System.out.printf("%d ", p.data);
      p = p.next;
    }
    System.out.print("\n");

    ListNode l = part(list,8);
    while(l != null){
      System.out.printf("%d ", l.data);
      l = l.next;
    }
    System.out.print("\n");
  }
}
