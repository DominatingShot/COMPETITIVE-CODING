#include <bits/stdc++.h>
using namespace std;

// Custom comparison function to sort pairs based on the second element (value)
bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.second > p2.second;  // Sort in descending order of values
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;

        // Calculate the frequency of each number
        for(int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }

        // Convert the map to a vector of pairs
        vector<pair<int, int>> pairs(m.begin(), m.end());

        // Sort the vector based on the frequency using the custom comparison function
        sort(pairs.begin(), pairs.end(), compare);

        vector<int> ans;
        // Extract the top k frequent numbers from the sorted pairs
        for(auto it = pairs.begin(); it != pairs.begin() + k; it++) {
            ans.push_back(it->first);
        }

        return ans;
    }
};

int main() {
    Solution s;

    // Test case
    vector<int> v = {1, 1, 1, 2, 2, 3};
    vector<int> ans = s.topKFrequent(v, 2);

    // Print the top k frequent numbers
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
