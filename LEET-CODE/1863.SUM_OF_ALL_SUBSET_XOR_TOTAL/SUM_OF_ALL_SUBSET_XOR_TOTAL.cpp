class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return helper(nums, 0, 0);
    }
    
    int helper(vector<int>& nums, int i, int curr) {
        if (i == nums.size()) {
            return curr; // When we've processed all elements, return the XOR result.
        }
        
        // Two recursive calls for each element: one where we include it, and one where we exclude it.
        return helper(nums, i + 1, curr ^ nums[i]) + helper(nums, i + 1, curr);
    }
};
