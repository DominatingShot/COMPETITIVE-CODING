class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m; // Create an unordered map to store the element-to-index mapping
        for (int i = 0; i < nums.size(); i++) {
            if (m[nums[i]] && i - m[nums[i]] <= k) // If the element is already in the map and the absolute difference between its current index 'i' and its previous index 'm[nums[i]]' is at most 'k'
                return true; // Return true as a duplicate element with a difference of at most 'k' exists
            m[nums[i]] = i; // Store the current index 'i' of the element in the map
        }
        return false; // Return false if no duplicate element with a difference of at most 'k' is found
    }
};
