class Solution {
    public TreeNode sortedListToBST(ListNode head) {
        // Call the helper function to convert the sorted linked list to a BST
        return helper(head, null);
    }
    
    public TreeNode helper(ListNode head, ListNode tail) {
        // Base case: If head and tail are the same node, there are no elements in the linked list
        // Return null to indicate the absence of a subtree
        if (head == tail)
            return null;
        
        // Base case: If head.next and tail are the same node, there is only one element in the linked list
        // Create a new TreeNode with the value of the current head node and return it as the root of the subtree
        if (head.next == tail)
            return new TreeNode(head.val);
        
        // Find the middle element of the linked list using the two-pointer technique
        ListNode slow = head;  // Slow pointer moves one step at a time
        ListNode fast = head;  // Fast pointer moves two steps at a time
        
        while (fast != tail && fast.next != tail) {
            slow = slow.next;
            fast = fast.next.next;
        }
        
        // Create a new TreeNode with the value of the middle element as the root of the subtree
        TreeNode root = new TreeNode(slow.val);
        
        // Recursive calls to construct the left and right subtrees
        // Left subtree: Use the elements before the middle element (from head to slow) and pass slow as the new tail
        root.left = helper(head, slow);
        
        // Right subtree: Use the elements after the middle element (from slow.next to tail) and pass slow.next as the new head
        root.right = helper(slow.next, tail);
        
        // Return the constructed root
        return root;
    }
}
