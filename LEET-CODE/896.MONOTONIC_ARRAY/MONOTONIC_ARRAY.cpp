class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int x = 0;  // Initialize a variable to track the relationship between elements.
        int eq = 0; // Initialize a variable to count the number of times elements are equal.

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                x -= 1;  // Decreasing relationship between elements.
            } else if (nums[i] < nums[i + 1]) {
                x += 1;  // Increasing relationship between elements.
            } else {
                eq += 1; // Elements are equal.
            }
        }

        if (x == (nums.size() - 1 - eq) || x == -(nums.size() - 1 - eq)) {
            return true;  // The array is either non-increasing or non-decreasing.
        }
        return false;  // The array is not monotonic.
    }
};
