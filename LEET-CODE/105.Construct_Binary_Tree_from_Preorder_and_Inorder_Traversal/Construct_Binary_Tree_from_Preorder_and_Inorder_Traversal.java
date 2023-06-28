class Solution {
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        // Call the helper function to construct the binary tree
        return helper(0, 0, inorder.length - 1, preorder, inorder);
    }
    
    public TreeNode helper(int pres, int ins, int ine, int[] preorder, int[] inorder) {
        // Base case: If the starting index of preorder is greater than the ending index
        // or the starting index of inorder is greater than the ending index, return null
        if (pres > preorder.length - 1 || ins > ine)
            return null;
        
        // Find the index of the current root value in the inorder array
        int inIndex = 0;
        for (int i = ins; i <= ine; i++) {
            if (inorder[i] == preorder[pres]) {
                inIndex = i;
                break;
            }
        }
        
        // Create a new TreeNode with the current root value
        TreeNode root = new TreeNode(preorder[pres]);
        
        // Recursive calls to construct the left and right subtrees
        // Left subtree: Start from the next element in the preorder array and use the appropriate indices
        root.left = helper(pres + 1, ins, inIndex - 1, preorder, inorder);
        
        // Right subtree: Start from the next element in the preorder array after skipping the left subtree elements
        // Use the appropriate indices for the inorder array
        root.right = helper(pres + inIndex - ins + 1, inIndex + 1, ine, preorder, inorder);
        
        // Return the constructed root
        return root;
    }
}
