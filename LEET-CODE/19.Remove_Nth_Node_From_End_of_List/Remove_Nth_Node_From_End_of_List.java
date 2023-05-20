/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 * @param <ListNode>
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode prev = null; // Stores the previous node
        ListNode temp = head; // Represents the current node
        ListNode temp2 = head; // Represents a pointer to the nth node from the end
        int x = 1; // Counter variable
        
        // Move the temp2 pointer n nodes ahead
        while (x < n) {
            temp2 = temp2.next;
            x++;
        }
        
        // Traverse until the temp2 pointer reaches the end of the list
        while (temp2.next != null) {
            temp2 = temp2.next;
            prev = temp; // Update the previous node
            temp = temp.next; // Move to the next node
        }
        
        // If the previous node is null, it means we need to remove the head node
        if (prev == null) {
            head = head.next;
        } else {
            prev.next = temp.next; // Skip the node to be removed
        }
        
        return head; // Return the modified linked list
    }
}
