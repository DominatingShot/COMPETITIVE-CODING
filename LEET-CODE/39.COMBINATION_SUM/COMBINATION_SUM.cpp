class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> t;
        combinationSumRec(candidates, target, 0, result, t);
        return result;
        
    }
    void combinationSumRec(vector<int>& candidates, int target, int begin, vector<vector<int>>& result, vector<int>& t) {
        if(target == 0) {
            result.push_back(t);
            return;
        }
        while(begin < candidates.size() && target - candidates[begin] >= 0) {
            t.push_back(candidates[begin]);
            combinationSumRec(candidates, target - candidates[begin], begin, result, t);
            begin++;
            t.pop_back();
        }

    }

};