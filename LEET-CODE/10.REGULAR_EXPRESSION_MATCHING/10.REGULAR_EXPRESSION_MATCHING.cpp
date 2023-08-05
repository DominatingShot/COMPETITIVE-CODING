//brute force
class Solution {
public:
    int m, n;
    vector<vector<int>> dp; // A 2D DP matrix to store the matching information between substrings of 's' and 'p'

    bool isMatch(string s, string p) {
        m = s.size();
        n = p.size();
        dp.resize(m + 1, vector<int>(n + 1, -1)); // Initialize the DP matrix with -1

        // Call the recursive helper function to check for matching
        isMatch(s, p, 0, 0);

        // Return the result from the DP matrix for the full strings 's' and 'p'
        return dp[0][0];
    }

    bool isMatch(string s, string p, int i, int j) {
        // Check if the result for current (i, j) has already been computed
        if (dp[i][j] != -1)
            return dp[i][j];

        // Base case: Both strings 's' and 'p' are exhausted, they match
        if (i >= m && j >= n)
            return true;

        // Base case: Pattern 'p' is exhausted but 's' is not, they don't match
        if (j >= n)
            return false;

        // Check if the current characters of 's' and 'p' match or if the pattern character is '.'
        bool match = (i < m && (s[i] == p[j] || p[j] == '.'));

        if (p[j + 1] == '*' && j + 1 < n) {
            // If the next pattern character is '*', then we can choose to match zero occurrences of the preceding character or repeat the current match
            dp[i][j] = isMatch(s, p, i, j + 2) || (match && isMatch(s, p, i + 1, j));
            return dp[i][j];
        } else {
            // If the next pattern character is not '*', then the current characters must match and we move to the next characters in both 's' and 'p'
            dp[i][j] = match && isMatch(s, p, i + 1, j + 1);
            return dp[i][j];
        }

        // The code should not reach this point, but to avoid any warnings, return false
        dp[i][j] = false;
        return false;
    }
};
