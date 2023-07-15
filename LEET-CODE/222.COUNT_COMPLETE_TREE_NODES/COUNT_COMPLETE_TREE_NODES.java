class Solution {
    int count = 0;
    
    public int countNodes(TreeNode root) {
        // If the root is null, return 0 since there are no nodes
        if (root == null) {
            return 0;
        }
        
        // Call the helper function to count the nodes
        helper(root);
        
        // Return the count of nodes
        return count;
    }
    
    public void helper(TreeNode root) {
        // If the current node is null, return
        if (root == null) {
            return;
        }
        
        // Increment the count of nodes
        count++;
        
        // Recursively traverse the left and right subtrees
        helper(root.left);
        helper(root.right);
    }
}
