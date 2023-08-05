//BFS
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL)
            return {}; // If the root is NULL (empty tree), return an empty vector.
        vector<int> ans; // Vector to store the rightmost nodes at each level.
        queue<TreeNode*> q; // Queue to perform level-order traversal of the tree.
        q.push(root); // Start with the root node.

        while (!q.empty()) { // Continue traversal until the queue becomes empty.
            int size = q.size(); // Get the number of nodes at the current level.

            while (size--) {
                TreeNode* curr = q.front(); // Get the front node from the queue.
                q.pop(); // Remove the front node from the queue.

                if (size == 0) {
                    ans.push_back(curr->val); // If size is 0, it means the current node is the rightmost node at its level.
                }

                // Add the left and right children of the current node to the queue if they exist.
                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
            }
        }
        return ans; // Return the vector containing the rightmost nodes at each level.
    }
};
