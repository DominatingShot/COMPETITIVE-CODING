class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result; // Create a vector to store the combinations.
        int i = 0; // Initialize a variable 'i' to track the current position in the combination.
        vector<int> p(k, 0); // Create a vector 'p' of size 'k' to store the current combination.

        while (i >= 0) { // Use a while loop to generate combinations.
            p[i]++; // Increment the current element in the combination.

            if (p[i] > n) {
                --i; // If the current element exceeds 'n', backtrack to the previous position.
            } else if (i == k - 1) {
                result.push_back(p); // If 'i' reaches 'k - 1', the combination is complete, so add it to the result.
            } else {
                ++i; // Move to the next position in the combination.
                p[i] = p[i - 1]; // Set the current element to the previous element to generate combinations.
            }
        }

        return result; // Return the vector containing all generated combinations.
    }
};
