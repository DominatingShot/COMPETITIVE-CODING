class Solution {
    List<Integer> l = new ArrayList<>();
    
    public List<Integer> postorderTraversal(TreeNode root) {
        // If the root is null, return the empty list
        if (root == null) {
            return l;
        }
        
        // Recursively traverse the left and right subtrees in postorder
        postorderTraversal(root.left);
        postorderTraversal(root.right);
        
        // Add the value of the current node to the list
        l.add(root.val);
        
        // Return the list containing the postorder traversal
        return l;
    }
}
