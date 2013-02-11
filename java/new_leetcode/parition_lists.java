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
    public ListNode partition(ListNode head, int x) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ListNode lt = new ListNode(0);
        ListNode gt = new ListNode(0);
        ListNode lt1 = lt;
        ListNode gt1 = gt;
        
        while(head != null){
            if(head.val < x){
                lt1.next = new ListNode(head.val);
                lt1 = lt1.next;
            }
            else{
                gt1.next = new ListNode(head.val);
                gt1 = gt1.next;
            }
            
            head = head.next;
        }
        
        lt1.next = gt.next;
    
        return lt.next;
    }
}
