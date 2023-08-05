class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0; // Initialize the left pointer 'i' to the start of the vector
        int j = numbers.size() - 1; // Initialize the right pointer 'j' to the end of the vector

        while (numbers[i] + numbers[j] != target) { // Loop until the sum of elements at 'i' and 'j' equals the target
            if (numbers[i] + numbers[j] > target) { // If the sum is greater than the target, decrement 'j' to reduce the sum
                j--;
            } else { // If the sum is less than the target, increment 'i' to increase the sum
                i++;
            }
        }

        // Return the indices (1-based) of the two numbers whose sum equals the target
        return {i + 1, j + 1};
    }
};
