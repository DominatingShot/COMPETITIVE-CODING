class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<int> temp = intervals[0]; // Initialize 'temp' with the first interval
        sort(intervals.begin(), intervals.end()); // Sort the intervals based on the starting value

        vector<vector<int>> ans; // Initialize the vector 'ans' to store the merged intervals

        // Iterate through the sorted intervals and merge overlapping intervals
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= temp[1]) {
                // If the current interval overlaps with 'temp', merge them by updating the end value of 'temp'
                temp[1] = max(temp[1], intervals[i][1]);
            } else {
                // If the current interval doesn't overlap with 'temp', add 'temp' to 'ans' and update 'temp' with the current interval
                ans.push_back(temp);
                temp = intervals[i];
            }
        }

        ans.push_back(temp); // Add the last merged interval or the single interval to 'ans'

        return ans; // Return the merged intervals
    }
};
