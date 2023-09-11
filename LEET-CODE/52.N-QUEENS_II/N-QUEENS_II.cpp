class Solution {
public:
    int x; // A counter to keep track of the total number of solutions.

    int totalNQueens(int n) {
        vector<string> temp(n, string(n, '.')); // Create an empty NxN chessboard represented by a vector of strings.
        helper(temp, 0, 0, n); // Start the recursive process to find solutions.
        return x; // Return the total number of solutions.
    }

    void helper(vector<string>& temp, int row, int column, int n) {
        if (row == n) {
            x++; // If a valid solution is found, increment the solution counter.
            return;
        }

        while (column < n) {
            if (isvalid(temp, row, column, n)) {
                temp[row][column] = 'Q'; // Place a queen at the current position.
                helper(temp, row + 1, 0, n); // Recursively try to place queens in the next row.
                temp[row][column] = '.'; // Backtrack by removing the queen from the current position.
            }
            column++;
        }
    }

    bool isvalid(vector<string>& temp, int row, int col, int n) {
        // Check if it's valid to place a queen at the current position without conflicts.
        for (int i = 0; i < row; i++) {
            if (temp[i][col] == 'Q') {
                return false; // Check for conflicts in the same column.
            }
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (temp[i][j] == 'Q') {
                return false; // Check for conflicts in the upper-left diagonal.
            }
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (temp[i][j] == 'Q') {
                return false; // Check for conflicts in the upper-right diagonal.
            }
        }
        return true; // No conflicts found, it's a valid placement.
    }
};