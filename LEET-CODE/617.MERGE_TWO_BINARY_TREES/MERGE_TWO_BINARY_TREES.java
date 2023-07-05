class Solution {
    public TreeNode mergeTrees(TreeNode root1, TreeNode root2) {
        if (root1 == null && root2 == null)
            return null;  // If both trees are empty, return null

        if (root1 == null)
            return root2;  // If one tree is empty, return the other tree

        if (root2 == null)
            return root1;  // If one tree is empty, return the other tree

        // Create a new TreeNode with the sum of the corresponding nodes in both trees
        TreeNode root = new TreeNode(root1.val + root2.val);

        // Recursively merge the left subtrees of both trees
        root.left = mergeTrees(root1.left, root2.left);

        // Recursively merge the right subtrees of both trees
        root.right = mergeTrees(root1.right, root2.right);

        return root;  // Return the merged tree
    }
}
