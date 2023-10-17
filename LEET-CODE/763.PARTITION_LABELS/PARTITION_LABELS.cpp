class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,pair<int,int>> m; // Create a map to store the first and last occurrence indices of each character.
        for (int i = 0; i < s.size(); i++) {
            if (m.find(s[i]) == m.end()) {
                m[s[i]] = make_pair(i, i); // If the character is encountered for the first time, initialize its indices.
            } else {
                m[s[i]].second = i; // If the character is encountered again, update its last occurrence index.
            }
        }
        vector<vector<int>> v; // Create a vector to store the pairs of first and last indices.
        for (auto it = m.begin(); it != m.end(); it++) {
            vector<int> temp;
            temp.push_back(it->second.first);
            temp.push_back(it->second.second);
            v.push_back(temp);
        }
        sort(v.begin(), v.end()); // Sort the pairs based on their first indices.

        vector<int> temp = v[0]; // Initialize a temporary vector with the first pair.
        vector<int> result; // Create a vector to store the lengths of the partitions.

        for (int i = 1; i < v.size(); i++) {
            if (v[i][0] < temp[1]) {
                temp[1] = max(v[i][1], temp[1]); // If there is an overlap, merge the current and next pair.
            } else {
                result.push_back(temp[1] - temp[0] + 1); // If there is no overlap, add the length of the current partition to the result.
                temp = v[i]; // Update the temporary vector with the next pair.
            }
        }
        result.push_back(temp[1] - temp[0] + 1); // Add the length of the last partition to the result.
        return result; // Return the vector containing the lengths of partitions.
    }
};
