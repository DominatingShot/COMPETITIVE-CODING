class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3) return 0; // If the vector contains less than three elements, return 0 as there's no solution

        int closest = nums[0] + nums[1] + nums[2]; // Initialize 'closest' with the sum of the first three elements
        sort(nums.begin(), nums.end()); // Sort the vector 'nums' in non-decreasing order

        // Iterate through the vector to find three elements whose sum is closest to 'target'
        for (int first = 0; first < nums.size() - 2; ++first) {
            int second = first + 1; // Set the index of the second element to the next index after the 'first'
            int third = nums.size() - 1; // Set the index of the third element to the last index

            // Continue the loop until 'second' is less than 'third'
            while (second < third) {
                int curSum = nums[first] + nums[second] + nums[third]; // Calculate the current sum of three elements

                // If the current sum is equal to 'target', return the sum (closest solution found)
                if (curSum == target) return curSum;

                // Check if the current sum is closer to the target than the current closest sum
                if (abs(target - curSum) < abs(target - closest)) {
                    closest = curSum; // If so, update the 'closest' sum to the current sum
                }

                // Move the pointers 'second' or 'third' based on the difference between the current sum and the target
                if (curSum > target) {
                    --third; // If the current sum is greater than the target, move the 'third' pointer to the left
                } else {
                    ++second; // If the current sum is less than the target, move the 'second' pointer to the right
                }
            }
        }

        return closest; // Return the sum of three elements that are closest to the target
    }
};
