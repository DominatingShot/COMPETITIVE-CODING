class Solution {
    public int maxDepth(TreeNode root) {
        if(root == null){
            return 0;
        }
        else{
            return depth(root, 0);
        }
    }
    public int depth(TreeNode root , int n){
        if(root == null){
            return n;
        }
        if(root.left == null && root.right == null){
            return n;
        }
        else{
            return Math.max(depth(root.left, n+1), depth(root.right, n+1));
        }
    }
}