class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // Step 1: Replace non-positive integers with a value greater than the array size.
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= 0)
                nums[i] = nums.size() + 1;
        }

        // Step 2: Mark the positions of the positive integers as negative to indicate presence.
        for (int i = 0; i < nums.size(); i++) {
            if (abs(nums[i]) <= nums.size()) {
                nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
            }
        }

        // Step 3: Find the first index with a positive value, which indicates the first missing positive.
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0)
                return i + 1;
        }

        // Step 4: If no positive values are found, return the next positive integer.
        return nums.size() + 1;
    }
};
