class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if(p == null && q == null) // If both the nodes are null, return true
            return true;
        if(p == null || q == null) // If one of the nodes is null, return false
            return false;
        if(p.val != q.val) // If the values of the nodes are not equal, return false
            return false;
        return isSameTree(p.left, q.left) && isSameTree(p.right, q.right); // Recursively check if the left and right subtrees are equal
    }
}