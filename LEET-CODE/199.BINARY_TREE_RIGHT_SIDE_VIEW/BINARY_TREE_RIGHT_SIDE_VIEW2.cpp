class Solution {
private:
    vector<int> ans; // Vector to store the rightmost nodes at each level.
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL)
            return {}; // If the root is NULL (empty tree), return an empty vector.
        dfs(root, 0); // Start the depth-first search (DFS) from the root node.
        return ans; // Return the vector containing the rightmost nodes at each level.
    }

    void dfs(TreeNode* root, int level) {
        if (root == NULL)
            return; // Base case: If the node is NULL, return from the current recursion.

        // If the size of the ans vector is less than or equal to the current level,
        // it means the current node is the rightmost node at its level.
        // So, add its value to the ans vector.
        if (ans.size() <= level)
            ans.push_back(root->val);

        // Perform DFS on the right subtree first to find the rightmost node at the next level.
        dfs(root->right, level + 1);

        // Perform DFS on the left subtree to find the rightmost node at the current level (if it exists).
        dfs(root->left, level + 1);
    }
};
