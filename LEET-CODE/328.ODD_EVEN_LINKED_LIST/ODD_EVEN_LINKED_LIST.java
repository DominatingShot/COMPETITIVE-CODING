/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode oddEvenList(ListNode head) {
        // Check if the list is empty or has at most two nodes
        // In such cases, no rearrangement is needed, so return the head as it is
        if (head == null || head.next == null || head.next.next == null)
            return head;
        else {
            // Create a new list for odd-indexed nodes with the first node
            ListNode oddHead = new ListNode(head.val);
            ListNode odd = oddHead;

            // Create a new list for even-indexed nodes with the second node
            ListNode evenHead = new ListNode(head.next.val);
            ListNode even = evenHead;

            // Start from the third node in the original list
            ListNode temp = head.next.next;
            
            // Traverse the original list and distribute nodes to odd and even lists alternately
            while (temp != null) {
                odd.next = new ListNode(temp.val);
                odd = odd.next;
                temp = temp.next;
                if (temp != null) {
                    even.next = new ListNode(temp.val);
                    even = even.next;
                    temp = temp.next;
                }
            }
            
            // Connect the last node of the odd list to the first node of the even list
            odd.next = evenHead;
            
            // Return the head of the rearranged list
            return oddHead;
        }
    }
}
