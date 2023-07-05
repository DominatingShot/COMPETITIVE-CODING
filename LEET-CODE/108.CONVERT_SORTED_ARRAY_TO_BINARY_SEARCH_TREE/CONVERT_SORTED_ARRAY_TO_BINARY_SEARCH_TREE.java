class Solution {
    // Convert a sorted array to a balanced binary search tree
    public TreeNode sortedArrayToBST(int[] nums) {
        return helper(nums, 0, nums.length-1); // Call the helper function to perform the conversion
    }
    
    // Helper function to recursively build the binary search tree
    public TreeNode helper(int[] nums, int l, int r) {
        if (l > r) 
            return null; // Base case: If the left index is greater than the right index, return null indicating an empty subtree
        
        int m = (l+r)/2; // Calculate the middle index to split the array into left and right subtrees
        
        TreeNode root = new TreeNode(nums[m]); // Create a new TreeNode with the value at the middle index as the root of the current subtree
        
        // Recursively build the left and right subtrees by dividing the array
        root.left = helper(nums, l, m-1); // Build the left subtree with elements from the left of the middle index
        root.right = helper(nums, m+1, r); // Build the right subtree with elements from the right of the middle index
        
        return root; // Return the root of the current subtree
    }
}
