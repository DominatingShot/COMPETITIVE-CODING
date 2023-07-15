class Solution {
    public boolean isBalanced(TreeNode root) {
        // If the root is null, the tree is considered balanced, so return true
        if (root == null) {
            return true;
        }
        
        // Call the helper function to check if the tree is balanced
        if (helper(root, 0) == -1) {
            return false;
        }
        
        // If the helper function does not return -1, the tree is balanced, so return true
        return true;
    }
    
    public int helper(TreeNode root, int height) {
        // If the current node is null, return 0 indicating the height
        if (root == null) {
            return 0;
        }
        
        // Increment the height
        height++;
        
        // Recursively calculate the height of the left and right subtrees
        int left = helper(root.left, height);
        int right = helper(root.right, height);
        
        // If either the left or right subtree is unbalanced, return -1
        if (left == -1 || right == -1) {
            return -1;
        }
        
        // If the absolute difference between the heights of the left and right subtrees is greater than 1, return -1
        if (Math.abs(left - right) > 1) {
            return -1;
        }
        
        // Return the maximum height of the left and right subtrees plus 1
        return Math.max(left, right) + 1;
    } 
}

