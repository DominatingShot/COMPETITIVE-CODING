#include <bits/stdc++.h>  // Include standard C++ libraries
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();  // Get the size of the input matrix (number of rows or columns)

        // Transpose the matrix
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);  // Swap elements across the main diagonal
            }
        }

        // Reverse each row of the matrix
        for (auto& row : matrix) {
            reverse(row.begin(), row.end());  // Reverse the elements in each row
        }
    }
};
