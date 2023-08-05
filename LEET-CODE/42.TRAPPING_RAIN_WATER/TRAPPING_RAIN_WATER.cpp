class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(); // Get the size of the input vector 'height'

        int left = 0, right = n - 1; // Initialize two pointers 'left' and 'right' at the start and end of the vector
        int left_max = 0, right_max = 0; // Initialize variables to store the maximum heights encountered from the left and right directions
        int ans = 0; // Initialize the variable to store the total trapped water amount

        while (left < right) { // Loop until 'left' and 'right' pointers meet or cross each other
            if (height[left] < height[right]) { // If the height at 'left' is less than the height at 'right'
                if (height[left] >= left_max) // If the height at 'left' is greater than or equal to the current left_max
                    left_max = height[left]; // Update the left_max to the current height
                else
                    ans += left_max - height[left]; // Otherwise, add the trapped water amount (difference between left_max and current height) to the answer
                left++; // Move the 'left' pointer to the right
            } else { // If the height at 'right' is less than or equal to the height at 'left'
                if (height[right] >= right_max) // If the height at 'right' is greater than or equal to the current right_max
                    right_max = height[right]; // Update the right_max to the current height
                else
                    ans += right_max - height[right]; // Otherwise, add the trapped water amount (difference between right_max and current height) to the answer
                right--; // Move the 'right' pointer to the left
            }
        }

        return ans; // Return the total trapped water amount
    }
};
