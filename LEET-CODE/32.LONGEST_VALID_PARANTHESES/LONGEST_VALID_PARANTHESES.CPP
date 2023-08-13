using namespace std;
#include <bits/stdc++.h>
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        for(int i=0;i<s.length();i++){
            if(s[i]='('){
                st.push(i);
            }
            else{
                if(!st.empty()){
                    st.pop();            
                }
                else{
                    st.push(i);
                }
            }
        }
        int longest = st.lenght();
        if(st.empty())
            return longest;
        int a=longest;
        longest=0;
        whiile(!st.empty()){
            int b=st.top();
            longest =max(longest,a-b-1);
            a=b;
        }
        longest=max(longest,a);
        return longest;
    }
};