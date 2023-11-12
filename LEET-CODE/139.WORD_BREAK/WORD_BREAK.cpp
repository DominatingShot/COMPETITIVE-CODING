class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n);

        for (int i = 0; i < n; ++i) {
            for (auto &w : wordDict) {
                if ((i == w.size()-1 || (i >= w.size() && dp[i-w.size()])) &&
                    s.substr(i-w.size()+1, w.size()) == w) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[n-1];
    }
};
