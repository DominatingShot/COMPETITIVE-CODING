class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result; // Initialize an empty vector to store the rows of Pascal's Triangle.

        if (numRows == 0) {
            return result; // If numRows is 0, return an empty result.
        }

        // Create the first row with a single element, which is always 1.
        vector<int> temp;
        temp.push_back(1);
        result.push_back(temp);

        for (int i = 1; i < numRows; i++) {
            vector<int> temp; // Initialize a new vector to store the current row.

            // The first element of each row is always 1.
            temp.push_back(1);

            // Calculate the middle elements of the row based on the previous row.
            for (int j = 1; j < i; j++) {
                temp.push_back(result[i - 1][j - 1] + result[i - 1][j]);
            }

            // The last element of each row is always 1.
            temp.push_back(1);

            result.push_back(temp); // Add the current row to the result.
        }

        return result; // Return the generated Pascal's Triangle.
    }
};
