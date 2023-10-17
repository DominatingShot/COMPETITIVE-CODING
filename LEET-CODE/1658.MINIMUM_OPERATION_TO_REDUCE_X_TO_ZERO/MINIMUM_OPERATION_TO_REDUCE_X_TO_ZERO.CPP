class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        
        // If x is 0, return the total number of elements in the array.
        if (x == 0) {
            return n;
        }

        int max_sum = 0;
        
        // Calculate the total sum of all elements in the array.
        for (int i = 0; i < n; i++) {
            max_sum += nums[i];
        }
        
        // The goal is to find a subarray with a sum equal to max_sum - x.
        x = max_sum - x;
        int curr_sum = 0;
        int max_len = -1;
        int left = 0;

        // Use a two-pointer approach to find the subarray.
        for (int right = 0; right < n; right++) {
            curr_sum += nums[right];
            
            // If the current sum exceeds x, move the left pointer to reduce the subarray's size.
            while (curr_sum > x && left <= right) {
                curr_sum -= nums[left];
                left++;
            }
            
            // If the current sum is equal to x, update the maximum subarray length.
            if (curr_sum == x) {
                max_len = max(max_len, right - left + 1);
            }
        }
        
        // If max_len is still -1, there's no subarray with the desired sum.
        if (max_len == -1) {
            return -1;
        }
        
        // Return the minimum number of elements to remove from both ends.
        return n - max_len;
    }
};
