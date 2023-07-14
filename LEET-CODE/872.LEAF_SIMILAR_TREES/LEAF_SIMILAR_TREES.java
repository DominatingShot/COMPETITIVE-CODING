class Solution {
    List<Integer> l = new ArrayList<>();
    int i=0;
    
    // Store the leaf nodes of root1 in the list l.
    void helper1(TreeNode root){
        if(root == null){
            return;
        }
        if(root.left == null && root.right == null){
            l.add(root.val);
        }
        helper1(root.left);
        helper1(root.right);
    }
    
    // Check if the leaf nodes of root2 match the leaf nodes stored in the list l.
    boolean helper2(TreeNode root){
        if(root == null){
            return true;
        }
        if(root.left == null && root.right == null){
            // If there are no more elements in the list l or the current leaf node value doesn't match,
            // return false indicating the leaf nodes are not similar.
            if(i>=l.size() || root.val != l.get(i)){
                return false;
            }
            i++;
        }
        // Recursively check the leaf nodes in the left and right subtrees of root2.
        return helper2(root.left) && helper2(root.right);
    }
    
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        // Populate the list l with the leaf nodes of root1.
        helper1(root1);
        
        // Check if the leaf nodes of root2 match the leaf nodes stored in the list l.
        boolean x = helper2(root2);
        
        // If all leaf nodes of root2 have been visited and matched successfully with list l,
        // and there are no more elements left in the list l, return true indicating the leaf nodes are similar.
        if(i == l.size() && x){
            return true;
        }
        
        // Otherwise, return false indicating the leaf nodes are not similar.
        return false;
    }
}
