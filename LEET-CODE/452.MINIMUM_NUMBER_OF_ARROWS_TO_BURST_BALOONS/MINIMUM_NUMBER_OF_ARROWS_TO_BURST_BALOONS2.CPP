class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 0 || points.size() == 1) {
            return points.size(); // If there are 0 or 1 balloons, return that count directly
        }
        
        sort(points.begin(), points.end()); // Sort the balloons based on their start positions
        
        vector<int> temp = points[0]; // Initialize a temporary vector to track current interval
        temp[0] = 1; // Initialize the arrow count as 1 for the first interval
        
        for(int i = 1; i < points.size(); i++) {
            if(points[i][0] <= temp[1]) {
                // If the start of the current balloon is less than or equal to the end of the current interval,
                // update the end of the current interval with the minimum of its current end and the end of the current balloon
                temp[1] = min(temp[1], points[i][1]);
            }
            else {
                temp[0]++; // Increment arrow count as a new arrow is needed to burst balloons in the new interval
                temp[1] = points[i][1]; // Update the end of the current interval with the end of the current balloon
            }
        }
        
        return temp[0]; // Return the final count of arrows needed
    }
};
