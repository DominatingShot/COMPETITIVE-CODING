class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int inf = m + n; // A value used to represent infinity in the matrix
        
        // First pass: Traverse from top-left to bottom-right
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int up = inf, left = inf; // Initialize distances to infinity
                
                if(mat[i][j] == 0) {
                    continue; // If the cell already contains 0, no need to update
                }
                
                // Calculate the minimum distance from above and left, if they exist
                if(i - 1 >= 0) {
                    up = mat[i - 1][j];
                }
                if(j - 1 >= 0) {
                    left = mat[i][j - 1];
                }
                
                // Update the current cell with the minimum of up and left distances + 1
                mat[i][j] = min(up, left) + 1;
            }
        }
        
        // Second pass: Traverse from bottom-right to top-left
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                int down = inf, right = inf; // Initialize distances to infinity
                
                if(mat[i][j] == 0) {
                    continue; // If the cell already contains 0, no need to update
                }
                
                // Calculate the minimum distance from below and right, if they exist
                if(i + 1 < m) {
                    down = mat[i + 1][j];
                }
                if(j + 1 < n) {
                    right = mat[i][j + 1];
                }
                
                // Update the current cell with the minimum of its current value and the minimum of down and right distances + 1
                mat[i][j] = min(mat[i][j], min(down, right) + 1);
            }
        }
        
        return mat; // Return the updated matrix
    }
};
