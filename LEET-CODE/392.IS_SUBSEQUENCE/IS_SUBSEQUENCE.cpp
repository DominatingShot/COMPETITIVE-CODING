class Solution {
public:
    bool isSubsequence(string s, string t) {
        map <char, int> m;
        for (int i = 0; i < t.size(); i++) {
            m[t[i]]++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (m[s[i]] == 0) {
                return false;
            }
            m[s[i]]--;
        }
        return true;
    }
};