class Solution {
public:
    int x;
    TreeNode* prev=NULL;
    int getMinimumDifference(TreeNode* root) {
        x=INT_MAX;
        getMinimum(root);
        return x;

    }
    void getMinimum(TreeNode* root){
        if(root==NULL){
            return;
        }
        getMinimum(root->left);
        if(prev!=NULL){
            x=min(x,root->val-prev->val);
        }
        prev=root;
        getMinimum(root->right);
        return;
    }
};