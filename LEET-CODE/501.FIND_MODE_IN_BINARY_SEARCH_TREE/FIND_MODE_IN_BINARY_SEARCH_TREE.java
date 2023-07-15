import java.util.Map;
//bad solution brute force
class Solution {
    Map<Integer, Integer> m = new HashMap<>();
    
    public int[] findMode(TreeNode root) {
        // If the root is null, return an empty array
        if (root == null) {
            return new int[0];
        }
        
        // Call the helper function to count the occurrences of each value in the binary tree
        helper(root);
        
        // Find the maximum occurrence count
        int maxCount = 0;
        for (int i : m.keySet()) {
            if (m.get(i) > maxCount) {
                maxCount = m.get(i);
            }
        }
        
        // Collect the values with the maximum occurrence count
        int[] arr = new int[m.size()];
        int j = 0;
        for (int i : m.keySet()) {
            if (m.get(i) == maxCount) {
                arr[j] = i;
                j++;
            }
        }
        
        // Return the array of modes (values with the maximum occurrence count)
        return Arrays.copyOfRange(arr, 0, j);
    }
    
    public void helper(TreeNode root) {
        // If the current node is null, return
        if (root == null) {
            return;
        }
        
        // Update the count of the current node's value in the map
        if (m.containsKey(root.val)) {
            m.put(root.val, m.get(root.val) + 1);
        } else {
            m.put(root.val, 1);
        }
        
        // Recursively traverse the left and right subtrees
        helper(root.left);
        helper(root.right);
    }
}
