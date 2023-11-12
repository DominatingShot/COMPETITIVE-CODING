class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(auto a:wordDict){
            st.insert(a);
        }
        vector<int> dp(s.size(),-1);
        return helper(0,st,s,dp);
    }
    bool helper(int i,unordered_set<string> &st,string &s,vector<int> &dp){
        if(i==s.size()){
            return 1;
        }
        string temp="";
        if(dp[i]!=-1){
            return dp[i];
        }
        for(int j=i;j<s.size();j++){
            temp=temp+s[j];
            if(st.find(temp)!=st.end()){
                if(helper(j+1,st,s,dp)){
                    dp[i]=1;
                    return dp[i];
                }
            }
        }
        dp[i]=0;
        return dp[i];

    }
};