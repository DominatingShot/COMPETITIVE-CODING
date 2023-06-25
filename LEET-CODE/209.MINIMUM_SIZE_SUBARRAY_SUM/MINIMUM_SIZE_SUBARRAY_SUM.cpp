class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();  // Get the size of the input vector 'nums'
        int ans = INT_MAX;  // Initialize the answer as the maximum possible value
        int sum = 0;  // Initialize the current sum as 0
        int i = 0;  // Initialize the start pointer 'i' as 0
        int j = 0;  // Initialize the end pointer 'j' as 0

        while (i < n) {  // Loop until the start pointer reaches the end of the vector
            sum += nums[i];  // Add the current element to the sum

            if (sum < target) {  // If the sum is less than the target
                i++;  // Move the start pointer to the next element
            } else {  // If the sum is greater than or equal to the target
                while (sum >= target) {  // Loop until the sum is greater than or equal to the target
                    ans = min(ans, i - j + 1);  // Update the answer by taking the minimum of the current answer and the length of the subarray (i-j+1)
                    sum -= nums[j];  // Subtract the element at the end pointer from the sum
                    j++;  // Move the end pointer to the next element
                }
                i++;  // Move the start pointer to the next element
            }
        }

        if (ans == INT_MAX) {  // If the answer remains as the maximum possible value
            return 0;  // Return 0 to indicate that no subarray was found
        }
        return ans;  // Return the minimum size of the subarray that sums to at least the target
    }
};
