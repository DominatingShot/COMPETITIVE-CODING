class Solution {
    TreeNode first;   // Node to store the first incorrect node in the inorder traversal
    TreeNode prev;    // Node to keep track of the previous node in the inorder traversal
    TreeNode middle;  // Node to store the middle incorrect node in the inorder traversal
    TreeNode last;    // Node to store the last incorrect node in the inorder traversal

    public void helper(TreeNode root) {
        if (root == null)
            return;
        
        helper(root.left);  // Traverse the left subtree
        
        // Check if the current node violates the BST property
        if (prev != null && root.val < prev.val) {
            if (first == null) {
                first = prev;
                middle = root;
            } else {
                last = root;
            }
        }
        
        prev = root;  // Update the previous node
        
        helper(root.right);  // Traverse the right subtree
    }
    
    public TreeNode recoverTree(TreeNode root) {
        if (root == null)
            return null;
        
        helper(root);  // Call the helper function to identify incorrect nodes
        
        // Swap the values of the first and last incorrect nodes
        if (first != null && last != null) {
            int temp = first.val;
            first.val = last.val;
            last.val = temp;
            return root;
        }
        
        // Swap the values of the first and middle incorrect nodes
        int temp = first.val;
        first.val = middle.val;
        middle.val = temp;
        
        return root;
    }
}
