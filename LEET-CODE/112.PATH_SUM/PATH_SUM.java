class Solution {
    public boolean hasPathSum(TreeNode root, int targetSum) {
        // If the root is null, there is no path, so return false
        if (root == null) {
            return false;
        }
        
        // Call the helper function to check if there is a path with the target sum
        return helper(root, targetSum, 0);
    }
    
    public boolean helper(TreeNode root, int targetSum, int sum) {
        // If the current node is null, there is no path, so return false
        if (root == null) {
            return false;
        }
        
        // Add the value of the current node to the sum
        sum += root.val;
        
        // If the current node is a leaf node (no left or right child)
        if (root.left == null && root.right == null) {
            // Check if the sum matches the target sum
            if (sum == targetSum) {
                return true;
            }
            return false;
        }
        
        // Recursively check if there is a path with the target sum in the left or right subtree
        return helper(root.left, targetSum, sum) || helper(root.right, targetSum, sum);
    }
}
