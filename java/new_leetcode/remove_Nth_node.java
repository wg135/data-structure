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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(n == 0)
          return head;
        
        ListNode sent = new ListNode(0);
        sent.next = head;
        
        ListNode prev = sent;
        ListNode curr = head;
        
        int count = 0;
        while(count < n){
            count++;
            curr = curr.next;
        }
        
        while(curr != null){
            prev = prev.next;
            curr = curr.next;
        }
        prev.next = prev.next.next;
        
        return sent.next;
    }
}
