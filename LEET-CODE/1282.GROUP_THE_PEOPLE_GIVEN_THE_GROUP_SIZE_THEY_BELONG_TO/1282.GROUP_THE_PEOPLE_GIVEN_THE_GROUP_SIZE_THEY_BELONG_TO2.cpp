class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> m; // Create an unordered map to group people by their group sizes.
        vector<vector<int>> result; // Initialize a vector to store the final result.

        for (int i = 0; i < groupSizes.size(); i++) {
            m[groupSizes[i]].push_back(i); // Add the person to the corresponding group based on their group size.

            if (m[groupSizes[i]].size() == groupSizes[i]) {
                // If the group size is reached, add the group to the result and clear it.
                result.push_back(m[groupSizes[i]]);
                m[groupSizes[i]].clear();
            }
        }

        return result; // Return the vector of grouped people.
    }
};
