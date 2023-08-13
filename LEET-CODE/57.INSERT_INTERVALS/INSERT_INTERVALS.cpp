class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        vector<int> temp = intervals[0];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<temp[1]){
                temp[1] = max(temp[1],intervals[i][1]);
            }
            else{
                ans.push_back(temp);
            }
        }
        ans.push_back(temp);
    }
};