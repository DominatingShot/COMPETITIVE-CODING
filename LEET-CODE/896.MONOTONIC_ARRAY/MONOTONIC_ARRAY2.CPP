class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool inc = true;  // A flag to track if the array is non-decreasing (initially assumed true).
        bool dec = true;  // A flag to track if the array is non-increasing (initially assumed true).

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                inc = false;  // If nums[i] > nums[i + 1], it's not non-decreasing.
            } else if (nums[i] < nums[i + 1]) {
                dec = false;  // If nums[i] < nums[i + 1], it's not non-increasing.
            }
        }

        if (!inc && !dec) {
            return false;  // If both flags are false, it's neither non-decreasing nor non-increasing.
        }

        return true;
    }
};
