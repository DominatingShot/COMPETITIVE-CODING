class Solution {
    long x = Long.MIN_VALUE; // Initialize a variable to keep track of the previously visited node's value, starting with the minimum possible value
    boolean flag = true; // Initialize a flag to indicate whether the binary tree is a valid BST

    public boolean isValidBST(TreeNode root) {
        if(root == null) 
            return true; // If the root is null, the tree is considered a valid BST

        else {
            isValidBST(root.left); // Recursively validate the left subtree
            
            if(root.val > x) { // Check if the current node's value is greater than the previously visited node's value
                x = root.val; // Update the previously visited node's value to the current node's value
            }
            else {
                flag = false; // Set the flag to false, indicating that the tree is not a valid BST
            }
            
            isValidBST(root.right); // Recursively validate the right subtree
        }
        
        return flag; // Return the flag indicating whether the binary tree is a valid BST
    }
}