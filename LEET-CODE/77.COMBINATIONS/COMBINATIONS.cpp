class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }
        vector<vector<int>> result;
        vector<int> temp;
        helper(result,temp,0,k,nums);
        return result;
    }
    void helper(vector<vector<int>>& result, vector<int>& temp, int begin ,int k, vector<int>& nums){
        if(temp.size()==k){
            result.push_back(temp);
            return;
        }
        while(begin<nums.size()){
            temp.push_back(nums[begin]);
            helper(result,temp,begin+1,k,nums);
            temp.pop_back();
            begin++;
        }
    }
};