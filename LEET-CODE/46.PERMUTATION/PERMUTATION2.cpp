class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size()==1){
            return {nums};
        }
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++){
            int n = nums.front();
            nums.erase(nums.begin(),nums.begin()+1);
            vector<vector<int>> temp = permute(nums);
            for(int j=0;j<temp.size();j++){
                temp[j].push_back(n);
                ans.push_back(temp[j]);
            }
            nums.push_back(n);
        }
        return ans;

    }
};
