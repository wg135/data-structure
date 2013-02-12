/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; next = null; }
 * }
 */
/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public TreeNode sortedListToBST(ListNode head) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int len = list_size(head);
        return creatlist(head, 0, len-1);
        
    }
    
    public int list_size(ListNode head){
        int len = 0;
        while(head != null){
            len++;
            head = head.next;
        }
        
        return len;
    }
    
    public TreeNode creatlist(ListNode head, int start, int end){
        if(start > end)
            return null;
        int middle = (start + end) / 2;
        
        ListNode p = head;
        for(int i=start; i<middle; i++)
            p = p.next;
        TreeNode root = new TreeNode(p.val);
        
        root.left = creatlist(head, start, middle - 1);
        root.right = creatlist(p.next, middle + 1, end);
        
        return root;
    }
}
