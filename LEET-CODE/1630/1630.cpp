class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) 
    {
        vector<bool> v;
        for(int i=0;i<l.size();i++){
            v.push_back(helper(nums,l[i],r[i]));
        }
        return v;
    }
    bool helper(vector<int>& nums,int l , int r ){
        int len = r-l+1;
        int max = nums[l];
        int min = nums[l];
        for(int i=l;i<=r;i++){
            if(nums[i]<min){
                min=nums[i];
            }
            else if(max<nums[i]){
                max=nums[i];
            }
        }
        if((max-min)%(len-1)!=0){
            return false;
        }
        int diff = (max-min)/(len-1);
        if(diff == 0)
            return true;
        vector<int> visited(len);
        for(int i=l;i<=r;i++){
            int val = nums[i];
            if((val - min)%diff!= 0)         
                return false;
            else {
                int pos = (val - min) / diff;
                if(visited[pos])           
                    return false;
                visited[pos] = true;           
            }
        }
        return true;
        } 
};