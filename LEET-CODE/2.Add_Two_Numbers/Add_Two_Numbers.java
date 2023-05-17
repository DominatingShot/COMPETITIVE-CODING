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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head = new ListNode();  // Create a new ListNode to store the head of the resulting linked list
        int carry = 0;  // Variable to store the carry value during addition
        ListNode temp = head;  // Temporary node to build the resulting linked list
        
        while (l1 != null || l2 != null || carry == 1) {
            int sum = carry;  // Initialize the sum with the carry value
            
            if (l1 != null) {
                sum += l1.val;  // Add the value from the first linked list
                l1 = l1.next;  // Move to the next node
            }
            
            if (l2 != null) {
                sum += l2.val;  // Add the value from the second linked list
                l2 = l2.next;  // Move to the next node
            }
            
            temp.next = new ListNode(sum % 10);  // Create a new node with the least significant digit of the sum
            temp = temp.next;  // Move the temporary node to the next node
            carry = sum / 10;  // Update the carry value for the next addition
        }
        
        return head.next;  // Return the head of the resulting linked list
    }
}

