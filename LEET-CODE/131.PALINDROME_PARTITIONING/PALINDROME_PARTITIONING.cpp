class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> temp;  
        helper(result,temp,s,0);
        return result;
    }
    void helper(vector<vector<string>>& result, vector<string>& temp, string s, int index){
        if(index==s.size()){
            result.push_back(temp);
            return;
        }
        for(int i=index;i<s.size();i++){
            if(ispalindrome(s.substr(index,i-index+1))){
                temp.push_back(s.substr(index,i-index+1));
                helper(result,temp,s,i+1);
                temp.pop_back();
            }
        }
    }
    bool ispalindrome(string s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};