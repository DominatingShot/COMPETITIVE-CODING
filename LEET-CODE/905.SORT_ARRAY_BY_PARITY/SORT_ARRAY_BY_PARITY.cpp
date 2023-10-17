class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int start = 0;         // Initialize a start pointer at the beginning of the array.
        int end = nums.size() - 1;  // Initialize an end pointer at the end of the array.

        while (start < end) {  // Continue while the start pointer is less than the end pointer.
            if (nums[start] % 2 == 0) {
                // If the number at the start pointer is even, move the start pointer to the right.
                start++;
            } else {
                // If the number at the start pointer is odd, swap it with the number at the end pointer,
                // and then move the end pointer to the left.
                swap(nums[start], nums[end]);
                end--;
            }
        }
        
        return nums;  // Return the modified array where even numbers come before odd numbers.
    }
};
