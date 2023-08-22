class Solution {
public:
    TreeNode* Ancestor;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            helper(root);
            return Ancestor;
    }
    int helper(TreeNode *root){
       if(root==NULL){
           return 0;
       }
        int left=helper(root->left);
        int right=helper(root->right);
        int mid=(root==p || root==q)?1:0;
        if(left+right+mid>=2){
            Ancestor=root;
        }
        return (left+right+mid>0)?1:0;

    }
};