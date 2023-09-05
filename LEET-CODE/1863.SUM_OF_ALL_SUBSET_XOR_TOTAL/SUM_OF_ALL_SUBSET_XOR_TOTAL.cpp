class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return helper(nums,0,0);
    }
    int helper(vector<int>& nums,int i,int curr){
        if(i==nums.size()){
            return curr;
        }
        return helper(nums,i+1,curr^nums[i])+helper(nums,i+1,curr);
    }
};