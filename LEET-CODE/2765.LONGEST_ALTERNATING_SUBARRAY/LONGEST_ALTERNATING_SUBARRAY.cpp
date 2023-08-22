class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int longest=0,cur=1;
        int x=-1;
        bool flag=false;
        for(int i=1;i<nums.size();i++){
            if(nums[i]+x==nums[i-1]){
                cur++;
                x=-x;
                flag=true;
            }
            else{
                longest=max(longest,cur);
                cur=1;
                x=-1;
                if(flag){
                    i--;
                    flag=false;
                }

            }
        }
    }
};
