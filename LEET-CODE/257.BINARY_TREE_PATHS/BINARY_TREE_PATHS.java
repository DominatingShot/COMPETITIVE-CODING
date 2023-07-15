class Solution {
    List<String> l = new ArrayList<>();
    
    public List<String> binaryTreePaths(TreeNode root) {
        // If the root is null, return the empty list
        if (root == null) {
            return l;
        }
        
        // Call the helper function to find all binary tree paths
        helper(root, "");
        
        // Return the list containing the binary tree paths
        return l;
    }
    
    public void helper(TreeNode root, String s) {
        // If the current node is null, return
        if (root == null) {
            return;
        }
        
        // Append the value of the current node to the string
        s = s + root.val;
        
        // If the current node is a leaf node (no left or right child), add the path to the list
        if (root.left == null && root.right == null) {
            l.add(s);
        }
        
        // Recursively traverse the left and right subtrees, passing the updated path
        helper(root.left, s + "->");
        helper(root.right, s + "->");
    }
}
