class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target + 1, 0); // Create a vector 'dp' to store the number of combinations for each target value.
        dp[0] = 1; // There is one way to make a sum of 0, which is by not selecting any number.

        for (int i = 1; i <= target; ++i) {
            for (int num : nums) {
                if (i - num >= 0) {
                    dp[i] += dp[i - num];
                }
            }
        }
        
        return dp[target]; // Return the number of combinations to reach the target sum.
    }
};
