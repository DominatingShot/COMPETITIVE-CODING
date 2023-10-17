class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int, int> m; // Initialize a map to store the count of each element.
        vector<int> ans; // Initialize a vector to store the majority elements.
        int x = nums.size() / 3; // Calculate the threshold for majority elements.

        for(int i = 0; i < nums.size(); i++) {
            m[nums[i]]++; // Count the occurrences of each element.
        }

        for(auto i : m) {
            if(i.second > x) {
                ans.push_back(i.first); // If an element's count is greater than the threshold, it's a majority element, so add it to the 'ans' vector.
            }
        }

        return ans; // Return the vector containing the majority elements.
    }
};
