class Solution {
    public TreeNode invertTree(TreeNode root) {
        if (root != null) {
            TreeNode temp = root.right; // Store the reference to the right subtree in a temporary variable
            root.right = root.left; // Replace the right subtree with the left subtree
            root.left = temp; // Replace the left subtree with the temporary variable holding the original right subtree
            invertTree(root.right); // Recursively invert the right subtree
            invertTree(root.left); // Recursively invert the left subtree
        }
        return root; // Return the root of the inverted binary tree
    }
}