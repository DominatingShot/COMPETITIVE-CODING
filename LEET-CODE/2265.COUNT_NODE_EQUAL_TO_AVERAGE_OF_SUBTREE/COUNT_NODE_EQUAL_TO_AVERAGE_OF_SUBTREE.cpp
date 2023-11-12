class Solution {
public:
    int ans=0;
    int averageOfSubtree(TreeNode* root) {
        helper(root);
        return ans;
    }
    pair<int,int> helper(TreeNode* node){
        if(node==NULL){
            return {0,0};
        }
        pair<int,int> lefttree=helper(node->left);
        pair<int,int> righttree=helper(node->right);
        int sum = lefttree.first+righttree.first+node->val;
        int count = 1+lefttree.second+righttree.second;
        int avg = sum/count;
        if(node->val==avg)

            ans++;
        return {sum,count};

    }
};