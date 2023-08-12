class Solution {
    public ListNode removeElements(ListNode head, int val) {
        ListNode temp = head; // Initialize a temporary pointer to traverse the linked list.
        ListNode prev = null; // Initialize a pointer to keep track of the previous node.

        while (temp != null) { // Traverse the linked list until the end.
            if (temp.val == val) { // If the value of the current node is equal to the target value.
                if (prev == null) { // If the current node is the head of the linked list.
                    head = temp.next; // Update the head to skip the current node.
                    temp = head; // Move the temporary pointer to the new head.
                } else {
                    prev.next = temp.next; // Update the 'next' pointer of the previous node to skip the current node.
                    temp = temp.next; // Move the temporary pointer to the next node.
                }
            } else {
                prev = temp; // Update the previous pointer to the current node.
                temp = temp.next; // Move the temporary pointer to the next node.
            }
        }

        return head; // Return the modified linked list.
    }
}
