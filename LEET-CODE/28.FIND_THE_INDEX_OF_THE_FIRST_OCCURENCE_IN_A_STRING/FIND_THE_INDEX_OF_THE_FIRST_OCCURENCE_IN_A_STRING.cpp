#include <bits/stdc++.h> //include standard C++ libraries
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        int temp=0;
        if(needle.size()==0 || haystack.size()==0)
            return -1;
        else if(needle.size()>haystack.size())
            return -1;
        else{
            for(int i=0;i<=haystack.size()-needle.size();i++){
                string s = haystack.substr(i,needle.size());
                cout<<s<<endl;
                cout<<i<<" "<<needle.size()+i<<endl;
                if(s==needle){
                    temp=1;
                    return i;
                }
            }
        }
        return -1;
    }
};