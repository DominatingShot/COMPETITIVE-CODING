class Solution {
    // Method to calculate the maximum depth of a binary tree
    public int maxDepth(TreeNode root) {
        // Check if the root is null, indicating an empty tree
        if (root == null) {
            return 0; // Return 0 as the depth of an empty tree is 0
        } else {
            // Call the helper method to calculate the depth of the tree
            return depth(root, 0);
        }
    }
    
    // Helper method to recursively calculate the depth of the binary tree
    public int depth(TreeNode root, int n) {
        // Check if the root is null, indicating a leaf node
        if (root == null) {
            return n; // Return the current depth as it is a leaf node
        }
        
        // Check if both the left and right children are null, indicating a leaf node
        if (root.left == null && root.right == null) {
            return n; // Return the current depth as it is a leaf node
        } else {
            // Calculate the maximum depth between the left and right subtree recursively
            return Math.max(depth(root.left, n + 1), depth(root.right, n + 1));
        }
    }
}
