class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        vector<int> ans(temperatures.size(),0);
        for(int i=temperatures.size()-1;i>-1;i--){
            while(!s.empty()){
                if(temperatures[s.top()]>temperatures[i]){
                    break;
                }
                s.pop();
            }
            if(!s.empty()){
               ans[i]=s.top()-i;
            }
            s.push(i);
        }
        return ans;
    }
};