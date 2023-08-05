class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();    // Get the number of rows in the board
        int m = board[0].size(); // Get the number of columns in the board

        vector<vector<int>> temp = board; // Create a temporary copy of the board to hold the next state

        // Iterate through each cell in the board to calculate the next state
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int live = 0; // Initialize a count for the number of live neighbors

                // Check the status of neighboring cells and update the 'live' count
                if (i > 0) {
                    if (temp[i - 1][j] == 1)
                        live++; // Top neighbor
                    if (j > 0 && temp[i - 1][j - 1] == 1)
                        live++; // Top-left neighbor
                    if (j < m - 1 && temp[i - 1][j + 1] == 1)
                        live++; // Top-right neighbor
                }

                if (i < n - 1) {
                    if (temp[i + 1][j] == 1)
                        live++; // Bottom neighbor
                    if (j > 0 && temp[i + 1][j - 1] == 1)
                        live++; // Bottom-left neighbor
                    if (j < m - 1 && temp[i + 1][j + 1] == 1)
                        live++; // Bottom-right neighbor
                }

                if (j > 0 && temp[i][j - 1] == 1)
                    live++; // Left neighbor
                if (j < m - 1 && temp[i][j + 1] == 1)
                    live++; // Right neighbor

                // Update the cell's state based on the Game of Life rules
                if (board[i][j] == 1) {
                    if (live < 2 || live > 3)
                        board[i][j] = 0; // Any live cell with fewer than 2 or more than 3 live neighbors dies
                } else if (board[i][j] == 0) {
                    if (live == 3)
                        board[i][j] = 1; // Any dead cell with exactly 3 live neighbors becomes a live cell
                }
            }
        }
    }
};
