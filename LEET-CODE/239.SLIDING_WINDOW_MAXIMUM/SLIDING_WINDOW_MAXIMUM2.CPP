class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k==1 || nums.size()==1 || nums.size()==0 || k==0){
            return nums;
        }
        vector<int> ans;
        deque<int> dq;
        for(int i=0;i<k;i++){
            while(!dq.empty() && dq.front()<=i-k;){
                dq.pop_front();
            }
            
        }
    }
};