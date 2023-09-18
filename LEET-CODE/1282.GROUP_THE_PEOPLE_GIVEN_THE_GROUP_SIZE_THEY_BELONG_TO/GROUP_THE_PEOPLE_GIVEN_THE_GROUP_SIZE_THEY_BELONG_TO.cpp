class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> result; // Initialize a vector to store the final result.

        for (int i = 0; i < groupSizes.size(); i++) {
            bool flag = false; // Initialize a flag to check if a suitable group exists.

            for (int j = 0; j < result.size(); j++) {
                if (groupSizes[result[j][0]] == groupSizes[i] && result[j].size() < groupSizes[i]) {
                    // If a group with the same size exists and has room for more members, add the person to the group.
                    result[j].push_back(i);
                    flag = true;
                    break;
                }
                flag = false;
            }

            if (!flag) {
                // If no suitable group exists, create a new group with the current person.
                vector<int> temp;
                temp.push_back(i);
                result.push_back(temp);
            }
        }

        return result; // Return the vector of grouped people.
    }
};
