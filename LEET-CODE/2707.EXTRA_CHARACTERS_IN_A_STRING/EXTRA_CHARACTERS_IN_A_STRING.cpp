class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        vector<int> dp(s.size() + 1, -1); // Create a vector to store minimum extra characters required.
        dp[s.size()] = 0; // Initialize the last element of the vector as 0, indicating no extra characters needed.
        unordered_map<string, int> map; // Create an unordered_map to store words from the dictionary and their frequencies.

        // Populate the unordered_map with words from the dictionary.
        for (auto word : dictionary) {
            map[word]++;
        }

        // Call the helper function to calculate the minimum extra characters required.
        return helper(0, dp, s, map);
    }

    int helper(int i, vector<int>& dp, string s, unordered_map<string, int>& map) {
        if (dp[i] != -1)
            return dp[i];

        int res = 1 + helper(i + 1, dp, s, map); // Initialize res with the maximum possible value.

        string temp = "";
        
        // Iterate through the characters of the string starting from index i.
        for (int j = i; j < s.size(); j++) {
            temp += s[j]; // Build a substring.
            
            // If the substring exists in the dictionary, update res with the minimum extra characters.
            if (map[temp]) {
                res = min(res, helper(j + 1, dp, s, map));
            }
        }
        
        dp[i] = res; // Store the minimum extra characters required for the current position i.
        return res;
    }
};
