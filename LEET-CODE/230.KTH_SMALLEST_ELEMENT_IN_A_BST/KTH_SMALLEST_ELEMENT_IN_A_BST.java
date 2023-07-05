class Solution {
    int number = 0; // Initialize a variable to store the kth smallest element found so far
    int count = 0; // Initialize a variable to keep track of the number of elements visited

    public int kthSmallest(TreeNode root, int k) {
        count = k; // Set the count variable to the given value of k
        helper(root); // Call the helper method to find the kth smallest element
        return number; // Return the kth smallest element
    }
  
    public void helper(TreeNode n) {
        if (n.left != null) 
            helper(n.left); // Recursively traverse the left subtree of the current node
        
        count--; // Decrement the count to keep track of visited elements
        
        if (count == 0) {
            number = n.val; // Update the number with the value of the current node, which is the kth smallest element
            return; // Exit the method since the kth smallest element is found
        }
        
        if (n.right != null) 
            helper(n.right); // Recursively traverse the right subtree of the current node
    }
}
