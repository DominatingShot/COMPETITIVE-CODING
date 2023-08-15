class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);  // Add the new interval to the list
        
        sort(intervals.begin(), intervals.end());  // Sort the intervals based on the start values
        
        vector<vector<int>> ans;
        vector<int> temp = intervals[0];  // Initialize temp interval with the first interval
        
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] <= temp[1]){
                // If there's an overlap with the current interval and the temp interval
                // Update the end of the temp interval with the maximum of current and previous intervals' end
                temp[1] = max(temp[1], intervals[i][1]);
            }
            else{
                // If there's no overlap with the current interval, push the temp interval into the answer
                ans.push_back(temp);
                temp = intervals[i];  // Update the temp interval to the current interval
            }
        }
        
        ans.push_back(temp);  // Push the last temp interval into the answer
        
        return ans;  // Return the merged intervals
    }
};
