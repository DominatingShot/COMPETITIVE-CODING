class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        for (int i = 1; i <= n; i++) {
            nums.push_back(i); // Create a vector 'nums' containing integers from 1 to n.
        }
        vector<vector<int>> result; // Create a vector to store the combinations.
        vector<int> temp; // Create a vector 'temp' to store the current combination.
        helper(result, temp, 0, k, nums); // Call the recursive helper function to find combinations.
        return result; // Return the vector containing all combinations.
    }

    // Recursive helper function to find combinations.
    void helper(vector<vector<int>>& result, vector<int>& temp, int begin, int k, vector<int>& nums) {
        if (temp.size() == k) { // If the current combination has reached size 'k', add it to the result.
            result.push_back(temp);
            return;
        }
        while (begin < nums.size()) {
            temp.push_back(nums[begin]); // Add the current number to the combination.
            helper(result, temp, begin + 1, k, nums); // Recursively find combinations with the remaining numbers.
            temp.pop_back(); // Backtrack by removing the last added number to explore other combinations.
            begin++; // Move to the next number in 'nums'.
        }
    }
};
