class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> s;     // Create a stack to store elements.
        int third = INT_MIN; // Initialize the variable "third" to negative infinity.

        // Traverse the "nums" array from right to left.
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] < third) {
                return true; // If we find a number less than "third," we have found a valid "132 pattern."
            }
            
            // While the stack is not empty and the current number is greater than the top of the stack.
            while (!s.empty() && nums[i] > s.top()) {
                third = s.top(); // Update the "third" with the top element of the stack.
                s.pop();         // Pop the top element of the stack.
            }
            
            s.push(nums[i]); // Push the current number onto the stack.
        }
        
        return false; // If no valid "132 pattern" is found, return false.
    }
};
