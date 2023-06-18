class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1;  // Initialize count to 1, as the first element is always allowed
        int i = *(nums.begin());  // Initialize i with the first element of nums
        for (auto i = nums.begin() + 1; i != nums.end(); i++) {
            // Iterate through the elements starting from the second element

            if (*i == *(i - 1)) {
                // If the current element is the same as the previous element
                count++;  // Increment the count of consecutive duplicates

                if (count > 2) {
                    // If the count exceeds 2 (more than two consecutive duplicates)
                    nums.erase(i);  // Erase the current element from nums
                    i--;  // Move the iterator back to the previous position
                }
            } else {
                // If the current element is different from the previous element
                count = 1;  // Reset the count to 1
            }
        }

        return nums.size();  // Return the size of nums after removing duplicates
    }
};
