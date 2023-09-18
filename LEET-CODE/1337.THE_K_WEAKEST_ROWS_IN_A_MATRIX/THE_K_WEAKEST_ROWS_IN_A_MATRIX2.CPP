class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size(); // Get the number of rows in the matrix.
        
        // Append the row index to each row in the matrix.
        for (int i = 0; i < n; i++) {
            mat[i].push_back(i);
        }
        
        // Sort the matrix based on the number of ones in each row and then by row index.
        sort(mat.begin(), mat.end());
        
        vector<int> result;
        
        // Extract the row indices of the k weakest rows.
        for (int i = 0; i < k; i++) {
            result.push_back(mat[i][mat[i].size() - 1]);
        }
        
        return result;
    }
};
