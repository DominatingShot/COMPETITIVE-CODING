class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if (root == NULL) {
            return {}; // If the root is NULL (empty tree), return an empty vector.
        }
        vector<double> v; // Vector to store the average values of each level.
        queue<TreeNode*> q; // Queue to perform level-order traversal of the tree.
        q.push(root); // Start with the root node.

        while (!q.empty()) { // Continue traversal until the queue becomes empty.
            int x = q.size(); // Get the number of nodes at the current level.
            double sum = 0; // Variable to store the sum of node values at the current level.

            for (int i = 0; i < x; i++) {
                TreeNode* curr = q.front(); // Get the front node from the queue.
                q.pop(); // Remove the front node from the queue.
                sum = sum + curr->val; // Add the value of the current node to the sum.

                // Add the left and right children of the current node to the queue if they exist.
                if (curr->right) {
                    q.push(curr->right);
                }
                if (curr->left) {
                    q.push(curr->left);
                }
            }

            v.push_back(double(sum) / double(x)); // Calculate and store the average value of the current level.
        }

        return v; // Return the vector containing the average values of each level.
    }
};
