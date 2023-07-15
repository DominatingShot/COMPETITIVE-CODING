class Solution {
    public TreeNode searchBST(TreeNode root, int val) {
        // If the root is null, return null since the value cannot be found
        if (root == null) {
            return null;
        }
        
        // Perform iterative search
        while (root != null) {
            if (root.val == val) {
                return root; // Found the node with the target value
            } else if (root.val > val) {
                root = root.left; // Traverse to the left subtree
            } else {
                root = root.right; // Traverse to the right subtree
            }
        }
        
        // The value is not found, return null
        return null;
    }
}
