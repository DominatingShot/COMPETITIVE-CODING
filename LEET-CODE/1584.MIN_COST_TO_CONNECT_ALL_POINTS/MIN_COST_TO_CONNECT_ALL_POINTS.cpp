class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();   // Get the number of points.
        int result = 0;          // Initialize the result variable to store the minimum cost.
        int edges = 0;           // Initialize the count of edges added to the minimum spanning tree.
        int curr = 0;            // Initialize the current point as the starting point.

        // Initialize an array to store the minimum distance from the current point to all other points.
        vector<int> dist(n, 10000000);

        while (++edges < n) {
            dist[curr] = INT_MAX;   // Mark the current point as visited by setting its distance to INT_MAX.
            int minj = curr;        // Initialize the index of the point with the minimum distance to itself.

            // Iterate through all points to update their distances from the current point.
            for (int j = 0; j < n; j++) {
                if (dist[j] != INT_MAX) {
                    // Update the distance with the Manhattan distance.
                    dist[j] = min(dist[j], abs(points[curr][0] - points[j][0]) + abs(points[curr][1] - points[j][1]));

                    // Update the index of the point with the minimum distance.
                    if (dist[j] < dist[minj])
                        minj = j;
                }
            }

            // Add the minimum distance to the result and update the current point.
            result += dist[minj];
            curr = minj;
        }

        return result;  // Return the minimum cost to connect all points.
    }
};
