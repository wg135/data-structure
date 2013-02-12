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
    public ListNode swapPairs(ListNode head) {
        // Start typing your Java solution below
        // DO NOT write main() function
        
        ListNode sent = new ListNode(0);
        sent.next = head;
        
        if(head == null)
            return null;
        
        ListNode pprev = sent;
        ListNode prev = head;
        ListNode curr = head.next;
        
        while(curr != null){
            prev.next = curr.next;
            curr.next = prev;
            pprev.next = curr;
            
            pprev = curr;
            curr = prev.next;
            
            if(curr != null){
                pprev = prev;
                prev = curr;
                curr = curr.next;
            }
        }
        return sent.next;
    }
}
