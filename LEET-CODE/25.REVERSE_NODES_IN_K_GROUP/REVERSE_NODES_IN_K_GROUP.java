class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        // Check if the input linked list is null or if it doesn't have at least 'k' nodes; if so, return the original list.
        if (head == null || !checkvalid(head, k)) {
            return head;
        }
        
        ListNode curr = head; // 'curr' points to the current node during iteration
        ListNode prev = null; // 'prev' points to the previous node of 'curr' during iteration
        ListNode next = null; // 'next' points to the next node of 'curr' during iteration
        int count = 0;        // Initialize a count to keep track of the nodes processed

        // Reverse every 'k' nodes in the linked list
        while (count < k && curr != null) {
            next = curr.next;   // Store the next node of 'curr' to avoid losing the reference
            curr.next = prev;   // Reverse the pointer to the previous node
            prev = curr;        // Move 'prev' to the current node for the next iteration
            curr = next;        // Move 'curr' to the next node for the next iteration
            count += 1;         // Increment the count of nodes processed
        }
        
        // After reversing 'k' nodes, 'prev' points to the new head of the reversed portion.
        // 'head' should now point to the last node of the reversed portion to connect with the next reversed group.
        // Recursively call 'reverseKGroup' on the remaining part of the linked list and set it as the next node of the current reversed group.
        head.next = reverseKGroup(next, k);
        
        // Return 'prev' as it is now the head of the reversed group.
        return prev;
    }
    
    // A helper function to check if the linked list has at least 'k' nodes.
    public Boolean checkvalid(ListNode head, int k) {
        int count = 0;
        ListNode temp = head;
        while (count < k && temp != null) {
            temp = temp.next;
            count += 1;
        }
        // If 'count' is less than 'k', it means there are fewer than 'k' nodes in the linked list.
        return count >= k;
    }
}
