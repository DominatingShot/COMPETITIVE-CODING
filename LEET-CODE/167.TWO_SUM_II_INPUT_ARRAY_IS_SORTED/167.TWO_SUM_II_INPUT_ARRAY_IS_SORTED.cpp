class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;
        while (i < j) {
            int sum = numbers[i] + numbers[j];
            if (sum == target) { // If the sum is equal to the target, return the indices (1-based).
                return {i + 1, j + 1};
            } else if (sum > target) { // If the sum is greater than the target, move the right pointer inward.
                j--;
            } else { // If the sum is less than the target, move the left pointer inward.
                i++;
            }
        }
        return {}; // If no valid indices are found, return an empty vector.
    }
};
