class Solution {
    public ListNode reverseList(ListNode head) {
        // Initialize temporary variables
        ListNode temp = head; // Temporarily store the current node during traversal
        ListNode prev = null; // Stores the previous node, initially set to null

        // Traverse the linked list
        while (temp != null) {
            ListNode next = temp.next; // Store the reference to the next node

            // Reverse the link direction
            temp.next = prev; // Make the current node point to the previous node

            // Update the previous and current nodes for the next iteration
            prev = temp; // Update the previous node to the current node
            temp = next; // Move to the next node

            // Note: At this point, the original "next" variable no longer references the next node
        }

        // Update the head reference to the last node (which is now the first node in the reversed list)
        head = prev;

        // Return the reversed list
        return head;
    }
}
