class Solution {
    int x = 0;
    
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        // Create a list of lists to store the zigzag level order traversal
        List<List<Integer>> l = new ArrayList<List<Integer>>();
        // Perform level order traversal and populate the list
        l = helper(root, 0, l);
        
        // Reverse the odd-indexed lists to achieve the zigzag pattern
        for (int i = 0; i < l.size(); i++) {
            if (i % 2 != 0) {
                Collections.reverse(l.get(i));
            }
        }
        
        // Return the zigzag level order traversal
        return l;
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

