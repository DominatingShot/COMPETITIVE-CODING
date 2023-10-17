class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int total = 0; // Initialize a variable 'total' to count the total number of identical pairs.
        int x = nums.size(); // Get the size of the input vector 'nums'.

        for(int i = 0; i < x - 1; i++) {
            if(nums[i] == 0) continue; // Skip if the current element is 0 to avoid duplicate counting.

            int count = 0; // Initialize a variable 'count' to count identical elements.
            
            for(int j = i + 1; j < x; j++) {
                if(nums[i] == nums[j]) {
                    count++; // Increase 'count' for each identical pair.
                    nums[j] = 0; // Mark the element as 0 to avoid counting it again.
                }
            }

            if(count > 0)
                total += count * (count + 1) / 2; // Calculate the number of pairs using the combination formula and update 'total'.
        }

        return total; // Return the total number of identical pairs.
    }
};
