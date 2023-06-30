class Solution {
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        return helper(0, postorder.length - 1, 0, inorder.length - 1, inorder, postorder);
    }

    public TreeNode helper(int posts, int poste, int ins, int ine, int[] inorder, int[] postorder) {
        // Base case: If the indices are invalid, return null indicating an empty subtree
        if (ins > ine || posts > poste)
            return null;

        // Find the index of the root value in the inorder array
        int rootin = ins;

        while (inorder[rootin] != postorder[poste]) {
            rootin++;
        }

        // Create a new TreeNode with the root value from the postorder array
        TreeNode root = new TreeNode(postorder[poste]);

        // Recursively build the left subtree
        // The left subtree includes elements from the inorder array between indices 'ins' and 'rootin - 1'
        // and elements from the postorder array between indices 'posts' and 'posts + rootin - 1 - ins'
        root.left = helper(posts, posts + rootin - 1 - ins, ins, rootin - 1, inorder, postorder);

        // Recursively build the right subtree
        // The right subtree includes elements from the inorder array between indices 'rootin + 1' and 'ine'
        // and elements from the postorder array between indices 'posts + rootin - ins' and 'poste - 1'
        root.right = helper(posts + rootin - ins, poste - 1, rootin + 1, ine, inorder, postorder);

        // Return the root node of the constructed binary tree
        return root;
    }
}
