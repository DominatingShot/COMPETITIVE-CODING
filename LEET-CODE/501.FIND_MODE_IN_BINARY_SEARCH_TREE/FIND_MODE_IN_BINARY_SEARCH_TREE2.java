class Solution {
    int max = 0;
    int count = 0;
    int prev = 0;
    List<Integer> l = new ArrayList<>();
    
    public int[] findMode(TreeNode root) {
        // If the root is null, return an empty array
        if (root == null) {
            return new int[0];
        }
        
        // Call the helper function to find the modes (values with the maximum occurrence count)
        helper(root);
        
        // Convert the list of modes to an array
        int[] arr = new int[l.size()];
        for (int i = 0; i < l.size(); i++) {
            arr[i] = l.get(i);
        }
        
        // Return the array of modes
        return arr;
    }
    
    public void helper(TreeNode root) {
        // If the current node is null, return
        if (root == null) {
            return;
        }
        
        // Traverse the left subtree
        helper(root.left);
        
        // Update the count and compare with the previous value
        if (prev == root.val) {
            count++;
        } else {
            count = 1;
        }
        
        // Update the maximum occurrence count and the list of modes
        if (count > max) {
            max = count;
            l.clear();
            l.add(root.val);
        } else if (count == max) {
            l.add(root.val);
        }
        
        // Update the previous value
        prev = root.val;
        
        // Traverse the right subtree
        helper(root.right);
    }
}
