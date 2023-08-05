class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size(); // Get the size of the input vector 'nums'

        if (n < 3) // Base case 1: If the vector contains less than three elements, return an empty vector
            return {};

        sort(nums.begin(), nums.end()); // Sort the input vector in non-decreasing order

        if (nums[0] > 0 || nums[n - 1] < 0) // Base case 2: If the smallest element is greater than zero or the largest element is less than zero, there can't be any triplet summing to zero
            return {};

        vector<vector<int>> ans; // Initialize the vector to store the triplets

        unordered_map<int, int> m; // Create an unordered map to store the value-to-index mapping

        for (int i = 0; i < n; i++) // Store the value-to-index mapping of elements in the unordered map
            m[nums[i]] = i;

        for (int i = 0; i < n - 2; i++) { // Traverse the array to fix the first number in the triplet
            if (nums[i] > 0) // If the fixed number is positive, stop here because we can't make it zero by searching further
                break;

            for (int j = i + 1; j < n - 1; j++) { // Use nested loop to search for the other two numbers in the triplet
                int x = nums[i] + nums[j];

                if (x > 0) // If the sum is positive, we need more negative numbers to make it zero, so break the inner loop
                    break;

                int target = 0 - x; // Calculate the target value to complete the triplet (make sum zero)

                if (m.count(target) && m[target] > j) { // Check if the target value is present in the map and its index is greater than the current 'j'
                    vector<int> temp = {nums[i], nums[j], target}; // Found a triplet, add it to the answer vector
                    ans.push_back(temp);
                }

                j = m[nums[j]]; // Move 'j' to the last occurrence of the current value (to avoid duplicate triplets)
            }

            i = m[nums[i]]; // Move 'i' to the last occurrence of the current value (to avoid duplicate triplets)
        }

        return ans; // Return the answer vector containing all unique triplets summing to zero
    }
};
