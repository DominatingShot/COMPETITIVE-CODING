class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root){
            root->val=0;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<TreeNode*> tempq;
            int sum = 0;
            while(n--){
                TreeNode* temp=q.front();
                q.pop();
                tempq.push_back(temp);
                if(temp->left){
                    q.push(temp->left);
                    sum=sum+temp->left->val;
                }
                if(temp->right){
                    q.push(temp->right);
                    sum=sum+temp->right->val;
                }  
            }
            for(auto node : tempq){
                int  t = sum;
                if(node->left)  
                    t -= node->left->val;
                if(node->right) 
                    t -= node->right->val;
                if(node->left)  
                    node->left->val = t;
                if(node->right) 
                    node->right->val = t;
        }
        }
        return root;
    }
};