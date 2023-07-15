class Solution {
    int y = 0;
    
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        // Create a list of lists to store the level order traversal in bottom-up order
        List<List<Integer>> l = new ArrayList<List<Integer>>();
        // Perform level order traversal and populate the list
        l = helper(root, 0, l);
        
        // Reverse the list to obtain the bottom-up order
        Collections.reverse(l);
        
        // Return the level order traversal in bottom-up order
        return l;
    }
    
    public List<List<Integer>> helper(TreeNode root, int level, List<List<Integer>> l) {
        // If the current node is null, return the list indicating the end of traversal
        if (root == null) {
            return l;
        }
        
        // Recursively traverse the right subtree, incrementing the level
        helper(root.right, level + 1, l);
        
        // Recursively traverse the left subtree, incrementing the level
        helper(root.left, level + 1, l);
        
        // Add a new empty list until the current level is covered
        while (l.size() >= level) {
            l.add(new ArrayList<Integer>());
        }
        
        // Add the value of the current node to the list of the current level
        l.get(level).add(root.val);
        
        // Return the updated list
        return l;
    }
}
