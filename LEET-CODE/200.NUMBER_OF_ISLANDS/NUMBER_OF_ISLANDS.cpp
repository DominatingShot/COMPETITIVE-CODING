class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();  // Get the number of rows in the grid
        int m = grid[0].size();  // Get the number of columns in the grid
        int count = 0;  // Initialize the count of islands
        vector<vector<bool>> visited(n, vector<bool>(m, false));  // Create a boolean matrix to keep track of visited cells

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {  // Check if it's unvisited land
                    count++;  // Increment the count as a new island is found
                    bfs(grid, visited, i, j);  // Perform Breadth-First Search to explore the island
                }
            }
        }
        return count;  // Return the total count of islands
    }

    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {
        visited[i][j] = true;  // Mark the current cell as visited
        int n = grid.size();  // Get the number of rows in the grid
        int m = grid[0].size();  // Get the number of columns in the grid

        queue<pair<int, int>> q;  // Create a queue for BFS
        q.push({i, j});  // Add the current cell to the queue

        while (!q.empty()) {
            int row = q.front().first;  // Get the row of the cell at the front of the queue
            int col = q.front().second;  // Get the column of the cell at the front of the queue
            q.pop();  // Remove the cell from the queue

            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (abs(i) == abs(j)) {
                        continue;  // Skip diagonal neighbors
                    }
                    int new_row = row + i;  // Calculate the new row of the neighbor cell
                    int new_col = col + j;  // Calculate the new column of the neighbor cell

                    if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m &&
                        grid[new_row][new_col] == '1' && !visited[new_row][new_col]) {
                        visited[new_row][new_col] = true;  // Mark the neighbor cell as visited
                        q.push({new_row, new_col});  // Add the neighbor cell to the queue for further exploration
                    }
                }
            }
        }
    }
};
