import java.util.*;
class Solution {
    List<Integer> list = new ArrayList<>(); // List to store the inorder traversal of the tree
    public List<Integer> inorderTraversal(TreeNode root) {
        if (root == null) // If the root is null, return the list
            return list;
        inorderTraversal(root.left); // Traversing the left subtree
        list.add(root.val); // Adding the root value to the list
        inorderTraversal(root.right); // Traversing the right subtree
        return list; // Returning the list
    }
}