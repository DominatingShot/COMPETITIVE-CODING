#include <bits/stdc++.h> //include standard C++ libraries
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(auto i:matrix){
            if(i[i.size()-1]<=target){
                return binary_search(i.begin(),i.end(),target);
            }
            else{
                break;
            }
        }
        return false;
    }
};