#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int> v){
    if(v.size()==1){
        return 0;
    }
    else if(v.size()==2){
        if(v[0]>v[1]){
            return 0;
        }
        else{
            return 1;
        }
    }
    else{
        int mid = v.size()/2;
        if(v[mid]>v[mid-1] && v[mid]>v[mid+1]){
            return mid;
        }
        else if(v[mid]>v[mid+1]){
            vector<int> v2(v.begin(), v.begin()+mid);
            return findPeakElement(v2);
        }
        else{
            vector<int> v2(v.begin()+mid, v.end());
            return findPeakElement(v2)+mid;
        }
        
    }
}
};