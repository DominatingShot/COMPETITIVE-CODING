class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> m;
        m['2']="abc";
        m['3']="def";
        m['4']="ghi";
        m['5']="jkl";
        m['6']="mno";
        m['7']="pqrs";
        m['8']="tuv";
        m['9']="wxyz";
        vector<string> result;
        if(digits.size()==0)
            return result;
        string temp="";
        helper(result,temp,m,0,digits);
        return result;

        
    }
    void helper(vector<string>& result, string& temp,unordered_map<char,string>& m, int begin, string& digits){
        if(begin==digits.size()){
            result.push_back(temp);
            return;
        }
        char c=digits[begin];
        int i=0;
        while(i<m[c].size()){
            temp=temp+m[c][i];
            helper(result,temp,m,begin+1,digits);
            temp.pop_back();
            i++;
        }
    }
};