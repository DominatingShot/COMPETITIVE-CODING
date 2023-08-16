//brute forcing
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 1 || nums.size() == 1 || nums.size() == 0 || k == 0) {
            return nums; // If k is 1, or the input size is 1 or 0, or k is 0, just return the input array
        }
        vector<int> res; // Vector to store the resulting maximum values
        deque<int> q; // Double-ended queue to store indices of potential maximum values
        
        int max_val = INT_MIN; // Initialize the current maximum value
        int max_index = -1; // Initialize the index of the current maximum value
        
        for (int i = 0; i < nums.size(); i++) {
            if (i < k - 1) { // Populate the deque with the first k-1 elements
                q.push_back(nums[i]);
                if (nums[i] > max_val) {
                    max_val = nums[i]; // Update the current maximum value
                    max_index = i; // Update the index of the current maximum value
                }
            } else { // For the rest of the elements
                if (nums[i] > max_val) {
                    max_val = nums[i]; // Update the current maximum value
                    max_index = i; // Update the index of the current maximum value
                }
                if (i - max_index >= k) {
                    // If the current maximum value is out of the sliding window, recompute the maximum within the window
                    max_val = INT_MIN;
                    for (int j = i - k + 1; j <= i; j++) {
                        if (nums[j] > max_val) {
                            max_val = nums[j]; // Update the current maximum value
                            max_index = j; // Update the index of the current maximum value
                        }
                    }
                }
                res.push_back(max_val); // Push the current maximum value into the result vector
            }
        }
        return res; // Return the vector of maximum values for each sliding window
    }
};
