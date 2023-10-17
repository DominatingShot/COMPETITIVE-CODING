class Solution {
public:
    // Custom comparison function to sort strings by length and lexicographically
    bool compare(string a, string b) {
        if (a.size() == b.size()) 
            return a < b;  // If the sizes are equal, use lexicographical order
        return a.size() < b.size();  // Otherwise, sort by length
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        if (n == 1)
            return 1;  // If there's only one word, its chain length is 1.

        sort(words.begin(), words.end(), compare);  // Sort the words using the custom comparison function.

        // Create a vector of unordered maps to store the chain length for each word length (up to 16 characters).
        vector<unordered_map<string, int>> dp(17);

        // Initialize the chain length for each word in the corresponding map.
        for (auto word : words) {
            dp[word.size()][word] = 1;
        }

        int ans = 0;  // Initialize the maximum chain length.

        for (int i = 1; i < 17; i++) {
            for (auto word : dp[i]) {
                for (int j = 0; j < word.first.size(); j++) {
                    string temp = word.first;
                    temp.erase(temp.begin() + j);  // Remove one character from the word.

                    if (dp[i - 1].find(temp) != dp[i - 1].end()) {
                        // If the modified word is in the previous chain, update the chain length.
                        dp[i][word.first] = max(dp[i][word.first], dp[i - 1][temp] + 1);
                    }
                }
                ans = max(ans, dp[i][word.first]);  // Update the maximum chain length.
            }
        }

        return ans;  // Return the maximum chain length in the words.
    }
};
