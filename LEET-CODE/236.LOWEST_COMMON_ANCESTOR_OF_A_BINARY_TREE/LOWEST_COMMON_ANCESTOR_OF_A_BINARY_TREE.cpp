class Solution {
public:
    TreeNode* Ancestor; // To store the lowest common ancestor
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Call the helper function to traverse the tree and find the lowest common ancestor
        helper(root, p, q);
        return Ancestor; // Return the lowest common ancestor
    }
    
    int helper(TreeNode *root, TreeNode *p, TreeNode *q) {
        if(root == NULL) {
            return 0; // Base case: return 0 for null nodes
        }
        
        int left = helper(root->left, p, q); // Recurse on the left subtree
        int right = helper(root->right, p, q); // Recurse on the right subtree
        int mid = (root == p || root == q) ? 1 : 0; // Check if the current node is either p or q
        
        // If either of the following conditions is true, then the current node is the lowest common ancestor
        if(left + right + mid >= 2) {
            Ancestor = root; // Update the lowest common ancestor
        }
        
        // Return 1 if the current node or its children are either p or q, otherwise return 0
        return (left + right + mid > 0) ? 1 : 0;
    }
};
