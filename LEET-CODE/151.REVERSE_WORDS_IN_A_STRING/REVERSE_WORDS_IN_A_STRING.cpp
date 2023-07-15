class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string temp = "";
        for(int i = s.size()-1; i>=0; i--){
            if(s[i] == ' '){
                if(temp == "")
                continue;
                v.push_back(temp);
                temp = "";
            }
            else{
                temp = s[i] + temp;
            }
       }
        if(temp != "")
            v.push_back(temp);
        string ans = "";
        for(int i = 0; i<v.size(); i++){
            ans += v[i];
            if(i != v.size()-1)
                ans += " ";
        }
        return ans;
    }
};