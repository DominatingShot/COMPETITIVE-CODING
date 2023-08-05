class Solution {
private:
    vector<int> v; // Vector to store the result range
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return {-1 , -1}; // If the vector is empty, return {-1, -1} as the target is not present
        helper(nums , target , 0 , nums.size() - 1); // Call the helper function to find the range of occurrences
        return v; // Return the vector containing the starting and ending indices of the target value's range
    }

    void helper(vector<int> &nums , int target , int left , int right) {
        if (left > right) {
            v.push_back(-1); // If the left index is greater than the right index, the target is not found
            v.push_back(-1); // So, add {-1, -1} to 'v' and return
        }

        int mid = (left + right) / 2; // Calculate the middle index

        if (nums[mid] == target) {
            while (mid >= 0 && nums[mid] == target)
                mid--; // Move the 'mid' index to the start of the target range
            v.push_back(++mid); // Add the starting index of the target range to 'v'

            while (mid < nums.size() && nums[mid] == target)
                mid++; // Move the 'mid' index to the end of the target range
            v.push_back(mid - 1); // Add the ending index of the target range to 'v'
        } else if (nums[mid] > target) {
            helper(nums , target , left , mid - 1); // Recursively search in the left half
        } else {
            helper(nums , target , mid + 1 , right); // Recursively search in the right half
        }
    }
};
