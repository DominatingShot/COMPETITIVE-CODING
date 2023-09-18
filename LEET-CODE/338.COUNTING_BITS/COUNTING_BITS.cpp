class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1,0); // Create a vector to store the count of 1s for integers from 0 to n.
        result[1] = 1; // Initialize the count of 1s for '1' as 1.
        for (int i = 2; i <= n; i++) {
            result[i] = result[i/2] + i % 2; // Calculate the count of 1s for integer 'i'.
        }
        return result; // Return the 'result' vector containing the counts.
    };
};
