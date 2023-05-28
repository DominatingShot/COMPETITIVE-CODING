class Node {
    public int val;
    public Node prev;
    public Node next;
    public Node child;
}

class Solution {
    public Node flatten(Node head) {
        Node temp = head; // Temporary node to iterate through the linked list
        
        while (temp != null) { // Iterate until the end of the linked list
            Node next = temp.next; // Store the next node temporarily
            
            if (temp.child != null) { // Check if the current node has a child
                Node child = flatten(temp.child); // Recursively flatten the child linked list
                
                temp.child = null; // Remove the child reference
                temp.next = child; // Set the child linked list as the next of the current node
                child.prev = temp; // Set the current node as the previous of the child linked list
                
                while (temp.next != null) { // Find the end of the newly added child linked list
                    temp = temp.next;
                }
                
                temp.next = next; // Connect the remaining part of the original linked list
                if (next != null) {
                    next.prev = temp; // Set the previous of the next node as the newly added child linked list
                }
            } else {
                temp = temp.next; // Move to the next node if there is no child
            }
        }
        
        return head; // Return the flattened linked list
    }
}
