class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0); // Create a dynamic programming array of size n+1 and initialize it with zeros.
        dp[1] = 1; // Initialize the base case for dp[1] to 1.
        dp[2] = 1; // Initialize the base case for dp[2] to 1.

        for(int i = 3; i < n+1; i++) {  // Start a loop from 3 up to n (inclusive).
            for(int j = 1; j < i; j++) {  // For each i, consider breaking it into j and i-j.
                dp[i] = max(dp[i], max(j*(i-j), j*dp[i-j]));  // Update dp[i] with the maximum product obtained by choosing different break points.
            }
        }

        return dp[n]; // Return the maximum product obtained for breaking the integer n.
    }
};
