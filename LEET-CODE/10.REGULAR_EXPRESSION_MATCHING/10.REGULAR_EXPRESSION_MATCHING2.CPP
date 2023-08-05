class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> f(m + 1, vector<bool>(n + 1, false)); // Create a 2D boolean vector 'f' of size (m+1) x (n+1) to store the matching information between 's' and 'p'

        f[0][0] = true; // Base case: Both empty strings match each other
        for (int i = 1; i <= m; i++)
            f[i][0] = false; // Empty pattern (p="") cannot match any non-empty string
        for (int j = 1; j <= n; j++)
            f[0][j] = j > 1 && '*' == p[j - 1] && f[0][j - 2]; // Initialize the matching for patterns with '*' at the beginning

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] != '*') {
                    f[i][j] = f[i - 1][j - 1] && (s[i - 1] == p[j - 1] || '.' == p[j - 1]); // If current pattern character is not '*', check for direct character matching or '.' (any character) matching
                } else {
                    f[i][j] = f[i][j - 2] || (s[i - 1] == p[j - 2] || '.' == p[j - 2]) && f[i - 1][j]; // If current pattern character is '*', consider either zero occurrences of preceding character or one or more occurrences
                }
            }
        }

        return f[m][n]; // Return the final matching result for the entire strings 's' and 'p'
    }
};
