#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& v) {
    int ans=INT_MIN;
    int sum=0;
    for(auto i=v.begin();i!=v.end();i++){
        sum+=*i;
        ans=max(ans,sum);
        if(sum<0){
            sum=0;
        }
    }
    return ans;
}
};