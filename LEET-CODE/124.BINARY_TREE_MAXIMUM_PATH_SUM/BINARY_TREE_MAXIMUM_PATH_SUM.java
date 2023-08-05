class Solution {
    int result = Integer.MIN_VALUE; // Initialize a variable 'result' to store the maximum path sum (initialize to the smallest possible value)

    public int maxPathSum(TreeNode root) {
        maxPathSumHelper(root); // Call the helper function 'maxPathSumHelper' to compute the maximum path sum
        return result; // Return the final computed maximum path sum
    }

    public int maxPathSumHelper(TreeNode root) {
        if (root == null) return 0; // Base case: If the current node is null, return 0 (no contribution to the path sum)

        // Recursively compute the maximum path sum in the left and right subtrees
        int left = Math.max(0, maxPathSumHelper(root.left)); // Max path sum in the left subtree (ignore negative values)
        int right = Math.max(0, maxPathSumHelper(root.right)); // Max path sum in the right subtree (ignore negative values)

        // Update the global result with the maximum path sum considering the current node as the highest node on the path
        result = Math.max(result, left + right + root.val);

        // Return the maximum path sum considering the current node as part of the path (only one subtree allowed to connect)
        return Math.max(left, right) + root.val;
    }
}
