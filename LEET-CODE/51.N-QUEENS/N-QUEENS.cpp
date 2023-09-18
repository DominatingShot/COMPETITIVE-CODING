class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result; // Initialize a vector to store the solutions.
        vector<string> temp(n, string(n, '.')); // Initialize a temporary chessboard with empty positions.

        // Call the helper function to find solutions, starting from the first row (row 0).
        helper(result, temp, 0, 0, n);
        
        return result; // Return the vector containing all solutions.
    }

    void helper(vector<vector<string>>& result, vector<string>& temp, int row, int column, int n) {
        if (row == n) {
            result.push_back(temp); // If we have placed queens in all rows, add the solution to the result.
            return;
        }

        while (column < n) {
            if (isvalid(temp, row, column, n)) { // Check if it's valid to place a queen in the current position.
                temp[row][column] = 'Q'; // Place a queen in the current position.
                helper(result, temp, row + 1, 0, n); // Recursively move to the next row (row + 1).
                temp[row][column] = '.'; // Backtrack by removing the queen from the current position.
            }
            column++;
        }
    }

    bool isvalid(vector<string>& temp, int row, int col, int n) {
        // Check if it's valid to place a queen in the current position without conflicts.
        for (int i = 0; i < row; i++) {
            if (temp[i][col] == 'Q') {
                return false; // There is a queen in the same column.
            }
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (temp[i][j] == 'Q') {
                return false; // There is a queen in the top-left diagonal.
            }
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (temp[i][j] == 'Q') {
                return false; // There is a queen in the top-right diagonal.
            }
        }
        return true; // It's a valid position to place a queen.
    }
};
