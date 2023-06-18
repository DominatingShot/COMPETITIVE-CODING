class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // Create a 2D vector of size n x n to store the result matrix
        vector<vector<int>> res(n, vector<int>(n));

        // Initialize variables for the boundaries of the matrix
        int top = 0;
        int left = 0;
        int right = n - 1;
        int bottom = n - 1;

        // Initialize a counter variable
        int a = 1;

        // Loop to fill the matrix in a spiral pattern
        while (top <= bottom && left <= right) {
            // Fill the top row from left to right
            for (int i = left; i <= right; i++) {
                res[top][i] = a;
                a++;
            }
            top++;

            // Fill the right column from top to bottom
            for (int i = top; i <= bottom; i++) {
                res[i][right] = a;
                a++;
            }
            right--;

            // Check if there is a bottom row to fill
            if (top <= bottom) {
                // Fill the bottom row in reverse from right to left
                for (int i = right; i >= left; i--) {
                    res[bottom][i] = a;
                    a++;
                }
                bottom--;
            }

            // Check if there is a left column to fill
            if (left <= right) {
                // Fill the left column in reverse from bottom to top
                for (int i = bottom; i >= top; i--) {
                    res[i][left] = a;
                    a++;
                }
                left++;
            }
        }

        // Return the generated matrix
        return res;
    }
};