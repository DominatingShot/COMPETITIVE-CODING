class Solution {
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        // If the root is null, return an empty list
        if (root == null) {
            return new ArrayList<List<Integer>>();
        }
        
        // Call the helper function to find all paths with the target sum
        return helper(root, 0, targetSum, new ArrayList<>(), new ArrayList<>());
    }
    
    public List<List<Integer>> helper(TreeNode root, int sum, int targetSum, List<Integer> temp, List<List<Integer>> l) {
        // If the current node is null, return the list of paths
        if (root == null) {
            return l;
        }
        
        // Add the value of the current node to the sum and temporary list
        sum += root.val;
        temp.add(root.val);
        
        // If the current node is a leaf node (no left or right child)
        if (root.left == null && root.right == null) {
            // Check if the sum matches the target sum
            if (sum == targetSum) {
                l.add(new ArrayList<>(temp));
            }
        }
        
        // Recursively find paths with the target sum in the left and right subtrees
        helper(root.left, sum, targetSum, temp, l);
        helper(root.right, sum, targetSum, temp, l);
        
        // Remove the last element from the temporary list
        temp.remove(temp.size() - 1);
        
        // Return the updated list of paths
        return l;
    }
}

