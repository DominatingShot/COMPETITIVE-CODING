class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL)
            return root; // If the root is NULL (empty tree), return NULL.

        queue<Node*> q; // Queue to perform level-order traversal of the tree.
        q.push(root); // Start with the root node.

        while (!q.empty()) { // Continue traversal until the queue becomes empty.
            int size = q.size(); // Get the number of nodes at the current level.
            Node* prev = NULL; // Pointer to keep track of the previously processed node at the same level.

            while (size--) {
                Node* curr = q.front(); // Get the front node from the queue.
                q.pop(); // Remove the front node from the queue.

                curr->next = prev; // Set the next pointer of the current node to the previously processed node at the same level.

                prev = curr; // Update the prev pointer to the current node for the next iteration.

                // Add the right and left children of the current node to the queue if they exist.
                if (curr->right) {
                    q.push(curr->right);
                }
                if (curr->left) {
                    q.push(curr->left);
                }
            }
        }
        return root; // Return the root of the modified binary tree with "Next Right Pointer" connections.
    }
};
