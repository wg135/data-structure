/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ListNode header = new ListNode(0);
        header.next = l1;
        
        merge_util(header, l2);
        
        return header.next;
    }
    
    public void merge_util(ListNode head, ListNode L2){
        ListNode p = head.next;
        ListNode prev = head;
        
        if(p == null)
          head.next = L2;
         
        while(p != null && L2 != null){
           if(p.val < L2.val){
               if(p.next != null){
                   prev = p;
                   p = p.next;
               }
               else{
                   p.next = L2;
                   break;
               }
           }
           else{
               ListNode tmp = L2.next;
               prev.next = L2;
               L2.next = p;
               prev = L2;
               L2 = tmp;
           }
        } 
    }
}
