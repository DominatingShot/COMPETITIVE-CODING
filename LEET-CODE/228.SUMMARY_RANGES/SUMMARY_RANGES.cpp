class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 0)
            return {}; // If the input vector is empty, return an empty vector

        if (nums.size() == 1)
            return {to_string(nums[0])}; // If there's only one element in the vector, return it as a single range

        int start = nums[0]; // Initialize 'start' with the first element in the vector
        int end = nums[0];   // Initialize 'end' with the first element in the vector
        vector<string> ans;  // Create a vector of strings to store the summary ranges

        // Traverse the sorted vector to find consecutive ranges
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == end + 1) {
                end = nums[i]; // If the next number is consecutive, update 'end' to include the current number
            } else {
                if (start == end) {
                    ans.push_back(to_string(start)); // If 'start' and 'end' are the same, add a single number to the summary ranges
                } else {
                    ans.push_back(to_string(start) + "->" + to_string(end)); // Otherwise, add a range to the summary ranges
                }
                start = nums[i]; // Reset 'start' to the current number for the next range
                end = nums[i];   // Reset 'end' to the current number for the next range
            }
        }

        // After the loop, add the last range to the summary ranges
        if (start == end) {
            ans.push_back(to_string(start));
        } else {
            ans.push_back(to_string(start) + "->" + to_string(end));
        }

        return ans; // Return the vector of summary ranges
    }
};
