import chapter2.*;

public class swap2{

public static ListNode swap(ListNode list){

  ListNode first = list;
  ListNode second, third, result;
  
  if((list == null)||(list.next == null))
    return list;
  
  second = first.next;
  result = second;
  third = second.next;
  
  while(second != null){
    second.next = first;
    first.next = ((third == null || third.next == null)? third: third.next);
    first = third;
    second = ((third == null || third.next == null)? third: third.next);
    third = (second == null? second: second.next);
  } 

  return result; 
}

public static void main(String[] args){
  int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  ListNode list = new ListNode(0);
  for(int data: array)
    list.addtoend(data);
  ListNode p = list;
  while(p != null){
    System.out.printf("%d ", p.data);
    p = p.next;
  } 
  System.out.printf("\n");

  ListNode tmp = swap(list);
  while(tmp != null){
    System.out.printf("%d ", tmp.data);
    tmp = tmp.next;
  }
  System.out.printf("\n");
}
}
