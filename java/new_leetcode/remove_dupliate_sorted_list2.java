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
    public ListNode deleteDuplicates(ListNode head) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ListNode sent = new ListNode(0);
        sent.next = head;
        
        ListNode curr = head;
        ListNode prev = sent;
        
        while(curr != null){
            boolean dup = false;
            while(curr.next != null && curr.val == curr.next.val){
                dup = true;
                curr = curr.next;
            }
            if(dup == true){
                prev.next = curr.next;
                curr = curr.next;
            }
            else{
                prev = curr;
                curr = curr.next;
            }
        }
     return sent.next;   
    }
}
