//recursive solution
class Solution {
    public boolean isSymmetric(TreeNode root) {
        if(root == null) // If the root is null, return true
            return true;
        return isEqaual(root.left, root.right); // Check if the left and right subtrees are equal
    }
    public boolean isEqaual(TreeNode p, TreeNode q) {
        if(p == null && q == null) // If both the nodes are null, return true
            return true;
        if(p == null || q == null) // If one of the nodes is null, return false
            return false;
        if(p.val != q.val) // If the values of the nodes are not equal, return false
            return false;
        return isEqaual(p.left, q.left) && isEqaual(p.right, q.right); // Recursively check if the left and right subtrees are equal
    }
}
