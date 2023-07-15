class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        // Create a list of lists to store the values of tree nodes level by level
        List<List<Integer>> l = new ArrayList<List<Integer>>();
        // Call the helper function to perform level order traversal and populate the list
        return helper(root, 0, l);
    }
    
    public List<List<Integer>> helper(TreeNode root, int level, List<List<Integer>> l) {
        // If the current node is null, return the list indicating the end of traversal
        if (root == null) {
            return l;
        }
        
        // If the current level is equal to the size of the list, create a new list for the current level
        if (l.size() == level) {
            l.add(new ArrayList<Integer>());
        }
        
        // Add the value of the current node to the list of the current level
        l.get(level).add(root.val);
        
        // Recursively traverse the left and right subtrees, incrementing the level
        helper(root.left, level + 1, l);
        helper(root.right, level + 1, l);
        
        // Return the updated list
        return l;
    }
}
