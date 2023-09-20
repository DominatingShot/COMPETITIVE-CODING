class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> arr(nums.size(), 0); // Initialize an auxiliary vector arr of the same size as nums with all elements set to 0.
        
        for (int i = 0; i < nums.size(); i++) {
            if (++arr[nums[i]] > 1) { // Increment the count of the current number in arr and check if it's greater than 1 (indicating a duplicate).
                return nums[i]; // If a duplicate is found, return the duplicate number.
            }
        }
        
        return 0; // If no duplicate is found, return 0 (assuming 0 is not part of the input).
    }
};
