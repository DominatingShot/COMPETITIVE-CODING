class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        vector<vector<int>> intervals; // Vector to store merged intervals
        sort(points.begin(), points.end()); // Sort the points based on start positions
        
        for(int i = 0; i < points.size(); i++) {
            if(intervals.empty()) {
                intervals.push_back(points[i]); // If intervals is empty, add the current point as a new interval
            }
            else {
                if(points[i][0] <= intervals.back()[1]) {
                    // If the start of the current point is less than or equal to the end of the last interval,
                    // merge the intervals by updating the end of the last interval with the minimum of the two
                    intervals.back()[1] = min(intervals.back()[1], points[i][1]);
                }
                else {
                    intervals.push_back(points[i]); // If the intervals don't overlap, add the current point as a new interval
                }
            }
        }
        
        return intervals.size(); // Return the number of merged intervals, which represents the minimum number of arrows needed
    }
};
