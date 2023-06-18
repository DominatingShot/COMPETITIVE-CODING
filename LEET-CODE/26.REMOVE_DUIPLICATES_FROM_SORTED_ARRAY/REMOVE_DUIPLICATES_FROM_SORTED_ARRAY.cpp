#include <bits/stdc++.h> //include standard C++ libraries
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s; //define a set to store the unique elements of the vector
        for(int i=0; i<nums.size(); i++){ //iterate through the vector
            s.insert(nums[i]); //insert the current element into the set
        }
        nums.assign(s.begin(), s.end()); //assign the elements of the set to the vectors
        return s.size(); //return the size of the set
    }
};