class Solution {
    int sum = 0;  // Initialize a variable to store the sum of numbers
    
    public int sumNumbers(TreeNode root) {
        number(root, 0);  // Call the helper function to calculate the sum
        return sum;  // Return the final sum
    }
    
    public void number(TreeNode root, int data) {
        if (root == null) {
            return;  // Base case: if the current node is null, return (end of recursion)
        }
        
        // Form the number by appending the current node's value to the existing number
        data = data * 10 + root.val;
        
        // Check if the current node is a leaf node (no left or right child)
        if (root.left == null && root.right == null) {
            sum = sum + data;  // If yes, add the formed number to the sum
        }
        
        // Recur for the left and right subtrees with the updated formed number
        number(root.left, data);   // Recur for the left subtree
        number(root.right, data);  // Recur for the right subtree
    }
}
