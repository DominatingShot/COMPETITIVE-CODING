class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(9, vector<int>(9, 1)); // Stores the occurrence count of numbers in each row
        vector<vector<int>> col(9, vector<int>(9, 1)); // Stores the occurrence count of numbers in each column
        vector<vector<int>> box(9, vector<int>(9, 1)); // Stores the occurrence count of numbers in each 3x3 box
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') { // Skip empty cells
                    int num = board[i][j] - '0' - 1; // Convert char digit to 0-based integer
                    int k = i / 3 * 3 + j / 3; // Determine the index of the corresponding 3x3 box
                    
                    // Check if the current number has already been used in the row, column, or box
                    if (row[i][num]-- <= 0 || col[j][num]-- <= 0 || box[k][num]-- <= 0)
                        return false;
                }
            }
        }
        
        // If the loop completes without returning false, the board is valid
        return true;
    }
};
