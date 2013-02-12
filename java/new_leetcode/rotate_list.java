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
    public ListNode rotateRight(ListNode head, int n) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ListNode prev = head;
        ListNode curr = head;
        int count = 0;
        
        if(n == 0 || head == null)
          return head;
          
        while(curr != null){
           count++;
           curr = curr.next;
           if(count == n)
             break;
        } 
        
        if(curr == null && count <= n)
          return rotateRight(head, n%count);
          
        while(curr.next !=null){
            curr = curr.next;
            prev = prev.next;
        }  
        
        ListNode sent = prev.next;
        prev.next = null;
        curr.next = head;
        
        return sent;
        
    }
}
