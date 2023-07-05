class Solution {
    public Node copyRandomList(Node head) {
        // Check if the original linked list is empty, return null
        if (head == null)
            return null;

        // Create a HashMap to store the mapping between original nodes and their copies
        HashMap<Node, Node> map = new HashMap<>();

        // Step 1: Create a copy of each node in the original linked list and store the mapping in the HashMap
        Node node = head;
        while (node != null) {
            // Create a new node with the same value as the current node
            Node copyNode = new Node(node.val);
            // Store the mapping between the original node and its copy in the HashMap
            map.put(node, copyNode);
            // Move to the next node in the original linked list
            node = node.next;
        }

        // Step 2: Update the next and random pointers of the copied nodes using the HashMap
        node = head;
        while (node != null) {
            // Get the copy of the current node from the HashMap
            Node copyNode = map.get(node);
            // Update the next pointer of the copied node by mapping it to the copy of the next node
            copyNode.next = map.get(node.next);
            // Update the random pointer of the copied node by mapping it to the copy of the random node
            copyNode.random = map.get(node.random);
            // Move to the next node in the original linked list
            node = node.next;
        }

        // Return the head of the copied linked list by retrieving it from the HashMap
        return map.get(head);
    }
}
