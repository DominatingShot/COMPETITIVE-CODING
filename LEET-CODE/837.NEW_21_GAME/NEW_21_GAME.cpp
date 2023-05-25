#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double new21Game(int N, int K, int maxPts) {
        // Create a vector to store the probabilities
        vector<double> dp(N+maxPts+1.0);

        if (K == 0) {
            // If the threshold is zero, the game is already won
            return 1.0;
        }

        if (N >= K + maxPts - 1) {
            // If it's possible to achieve a score greater than or equal to the threshold, return 1.0
            return 1.0;
        }

        double prob = 0.0;
        double currsum = 1.0;

        // Initialize the first element of the vector to 1.0
        dp[0] = 1.0;

        for (int i = 1; i <= N; i++) {
            // Calculate the probability for each score
            dp[i] = currsum / (maxPts * 1.0);

            if (i < K) {
                // If the score is less than the threshold, update the current sum
                currsum += dp[i];
            } else {
                // If the score is greater than or equal to the threshold, update the probability
                prob += dp[i];
            }

            if (i >= maxPts) {
                // Subtract the probability of the score that falls out of the window
                currsum -= dp[i - maxPts];
            }
        }

        return prob;
    }
};
