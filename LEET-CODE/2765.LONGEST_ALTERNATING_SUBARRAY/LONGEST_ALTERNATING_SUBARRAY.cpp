class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int longest = 0; // To store the length of the longest alternating subarray
        int cur = 1; // Current length of the alternating subarray
        int x = -1; // Value to alternate between 1 and -1
        bool flag = false; // Flag to track if a valid alternating subarray was found
        
        for(int i = 1; i < nums.size(); i++) {
            // Check if the current element and its previous element form an alternating sequence
            if(nums[i] + x == nums[i - 1]) {
                cur++; // Increment the length of the current alternating subarray
                x = -x; // Toggle the value of x to alternate between 1 and -1
                flag = true; // Set the flag to indicate a valid alternating subarray
            }
            else {
                longest = max(longest, cur); // Update the longest length
                cur = 1; // Reset the current length for the next alternating subarray
                x = -1; // Reset x to -1 for the next sequence
                if(flag) {
                    i--; // If a valid alternating subarray was found, backtrack i
                    flag = false; // Reset the flag
                }
            }
        }
        
        return max(longest, cur); // Return the maximum of the current and longest lengths
    }
};
