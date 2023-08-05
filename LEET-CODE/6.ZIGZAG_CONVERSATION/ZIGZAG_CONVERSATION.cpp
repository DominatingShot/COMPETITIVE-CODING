class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size())
            return s; // If numRows is 1 or greater than or equal to the string size, no conversion needed, return the original string.

        vector<string> rows(numRows); // Create a vector of strings to represent the rows for zigzag conversion.
        int row = 0, step = 1; // Initialize the row index and step (1 for down, -1 for up).

        for (char c : s) { // Iterate through each character in the string.
            rows[row].push_back(c); // Add the current character to the corresponding row.

            // Check whether to move up or down for the next character.
            if (row == 0)
                step = 1; // If we reach the first row, change the direction to move down.
            else if (row == numRows - 1)
                step = -1; // If we reach the last row, change the direction to move up.

            row += step; // Update the row index based on the step direction.
        }

        s.clear(); // Clear the original string to store the zigzag converted string.

        for (int i = 0; i < numRows; i++) { // Concatenate all rows to form the zigzag converted string.
            s += rows[i];
        }

        return s; // Return the zigzag converted string.
    }
};
