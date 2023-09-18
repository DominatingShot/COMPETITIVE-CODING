class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;

        // Find the first index 'i' from the right such that nums[i-1] < nums[i].
        while (i > 0 && nums[i - 1] >= nums[i]) {
            i--;
        }

        if (i == 0) {
            // If 'i' becomes 0, it means the current permutation is the largest possible.
            // In this case, reverse the entire vector to get the smallest permutation.
            reverse(nums.begin(), nums.end());
            return;
        }

        // Find the index 'j' from the right such that nums[j] > nums[i-1].
        int k = i - 1;
        int j = nums.size() - 1;
        while (nums[j] <= nums[k]) {
            j--;
        }

        // Swap nums[k] and nums[j] to get the next permutation.
        swap(nums[k], nums[j]);

        // Reverse the elements to the right of 'k' to ensure the smallest permutation of the remaining elements.
        reverse(nums.begin() + k + 1, nums.end());
    }
};
