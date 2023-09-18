class Solution {
public:
    int x; // This variable will store the minimum absolute difference.
    TreeNode* prev = NULL; // This pointer will keep track of the previous node in an in-order traversal.
    
    int getMinimumDifference(TreeNode* root) {
        x = INT_MAX; // Initialize the minimum difference as the maximum possible integer value.
        getMinimum(root); // Call the helper function to compute the minimum difference.
        return x; // Return the minimum absolute difference.
    }
    
    // Helper function to perform an in-order traversal and compute the minimum difference.
    void getMinimum(TreeNode* root) {
        if (root == NULL) {
            return; // Base case: If the current node is NULL, return.
        }
        
        getMinimum(root->left); // Recursively traverse the left subtree.
        
        if (prev != NULL) {
            // Calculate the absolute difference between the current node and the previous node.
            x = min(x, root->val - prev->val);
        }
        
        prev = root; // Update the 'prev' pointer to the current node.
        
        getMinimum(root->right); // Recursively traverse the right subtree.
        
        return; // Return to the caller.
    }
};
