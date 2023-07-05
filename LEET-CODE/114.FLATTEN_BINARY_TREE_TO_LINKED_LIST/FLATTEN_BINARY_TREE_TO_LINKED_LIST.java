class Solution {
    TreeNode flatten;       // Reference to the flattened tree
    TreeNode flattenend;    // Reference to the end of the flattened tree

    public void flatten(TreeNode root) {
        if (root == null) {
            return;
        }
        
        traversal(root);  // Call the traversal method to flatten the tree
        
        // Update the root node to match the flattened tree
        root.val = flatten.val;
        root.left = null;
        flatten = flatten.right;
        
        // Create the remaining nodes of the flattened tree
        while (flatten != null) {
            root.right = new TreeNode(flatten.val);
            root.left = null;
            root = root.right;
            flatten = flatten.right;
        }
    }
    
    public void traversal(TreeNode root) {
        if (root == null) {
            return;
        }
        
        // Create the flattened tree nodes in a pre-order traversal
        if (flatten == null) {
            flatten = new TreeNode(root.val);
            flattenend = flatten;
        } else {
            flattenend.right = new TreeNode(root.val);
            flattenend.left = null;
            flattenend = flattenend.right;
        }
        
        // Recursively traverse the left and right subtrees
        traversal(root.left);
        traversal(root.right);
    }
}
