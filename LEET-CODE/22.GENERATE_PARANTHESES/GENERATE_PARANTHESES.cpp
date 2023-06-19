#include <bits/stdc++.h> //include standard C++ libraries
using namespace std;
class Solution {
public:
    vector<string> v;
    string s = "";
    vector<string> generateParenthesis(int n) {
        back(0,0,n);
        return v;
    }
    void back(int open , int close , int n){
            if(open == n && close == n){
                v.push_back(s);
            }
            if(open < n){
                s.push_back('(');
                back(open+1, close, n);
                s.pop_back();
            }
            if(close < open){
                s.push_back(')');
                back(open, close+1 ,n);
                s.pop_back();
            }
        }
};