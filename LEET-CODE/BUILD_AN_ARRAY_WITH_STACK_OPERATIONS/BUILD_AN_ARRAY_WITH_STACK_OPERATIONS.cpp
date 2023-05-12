#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
      vector<string> v;
      int j=0;
      for(int i=1;i<=*(target.end()-1);i++){
       if(target[i-1-j]==i){
        v.push_back("Push");
      }
       else{
        cout<<i;
        v.push_back("Push");
        v.push_back("Pop");
        j=j+1;
      }  
    }
        return v;
}
};