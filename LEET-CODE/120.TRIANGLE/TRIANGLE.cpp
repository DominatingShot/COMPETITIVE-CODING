class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> mini = triangle[triangle.size() - 1];
        // Initialize the "mini" vector with the last row of the triangle.

        for (int i = triangle.size() - 2; i >= 0; i--) {
            // Starting from the second-to-last row and moving upwards.
            for (int j = 0; j < triangle[i].size(); j++) {
                // Iterate through the elements of the current row.

                // Calculate the minimum path sum for the current element.
                mini[j] = triangle[i][j] + min(mini[j], mini[j + 1]);
                // The minimum path sum is the sum of the current element and the minimum of the two adjacent elements in the row below.

                // Update the "mini" vector with the new minimum path sum for this element.
            }
        }

        return mini[0];
        // The final result is stored in the first element of the "mini" vector, which represents the minimum path sum from the top to the bottom of the triangle.
    }
};
