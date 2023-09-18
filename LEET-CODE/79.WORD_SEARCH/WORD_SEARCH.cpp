class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0)
            return false; // If the board is empty, the word cannot exist.

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                // Iterate through each cell of the board to search for the word.
                if (helper(board, word, i, j, 0))
                    return true; // If the word is found, return true.
            }
        }

        return false; // If the word is not found in any starting position, return false.
    }

    bool helper(vector<vector<char>>& board, string word, int i, int j, int index) {
        if (index == word.size())
            return true; // If the entire word has been matched, return true.

        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '*' || board[i][j] != word[index])
            return false; // Check for boundary conditions and invalid cells.

        char temp = board[i][j]; // Store the original character at this cell.
        board[i][j] = '*'; // Mark the cell as visited.

        // Recursively check the neighboring cells in all four directions.
        bool res = helper(board, word, i + 1, j, index + 1) ||
                   helper(board, word, i - 1, j, index + 1) ||
                   helper(board, word, i, j + 1, index + 1) ||
                   helper(board, word, i, j - 1, index + 1);

        board[i][j] = temp; // Restore the original character.
        return res;
    }
};
