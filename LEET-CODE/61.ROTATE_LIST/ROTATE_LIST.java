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
    public ListNode rotateRight(ListNode head, int k) {
        int c = 1;  // Variable to count the number of nodes in the list
        ListNode temp = head;  // Temporary pointer to traverse the list

        if (head == null)
            return null;  // If the list is empty, return null
        if (head.next == null)
            return head;  // If the list has only one node, return the list as it is

        while (temp.next != null) {
            temp = temp.next;  // Traverse to the end of the list
            c++;  // Count the number of nodes in the list
        }

        int x = k % c;  // Calculate the actual number of rotations needed

        if (x == 0)
            return head;  // If the number of rotations is zero, return the list as it is

        temp = head;  // Reset the temporary pointer to the beginning of the list

        for (int i = 0; i < c - x - 1; i++)
            temp = temp.next;  // Move the pointer to the node just before the new head after rotations

        ListNode newHead = temp.next;  // Assign the new head after rotations
        temp.next = null;  // Set the next pointer of the new tail node to null

        ListNode temp2 = newHead;  // Temporary pointer to traverse to the end of the rotated list

        while (temp2.next != null)
            temp2 = temp2.next;  // Traverse to the end of the rotated list

        temp2.next = head;  // Connect the end of the rotated list to the original head

        return newHead;  // Return the new head of the rotated list
    }
}
