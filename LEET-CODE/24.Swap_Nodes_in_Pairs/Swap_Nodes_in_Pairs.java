
class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode temp = head; // Initialize a temporary node as head

        // Continue swapping pairs until either the current node or the next node is null
        while (temp != null && temp.next != null) {
            int temp1 = temp.val; // Store the value of the current node
            temp.val = temp.next.val; // Replace the value of the current node with the value of the next node
            temp.next.val = temp1; // Replace the value of the next node with the stored value
            
            // Move to the next pair if it exists
            if (temp.next.next != null) {
                temp = temp.next.next; // Move two steps forward
            } else {
                break; // Break the loop if there is no more pair
            }
        }
        
        return head; // Return the head of the modified linked list
    }
}
