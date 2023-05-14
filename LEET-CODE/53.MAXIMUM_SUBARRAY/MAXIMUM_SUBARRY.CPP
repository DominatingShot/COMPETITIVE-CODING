#include <bits/stdc++.h> //include standard C++ libraries
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& v) { //define a function maxSubArray that takes a vector of integers as input and returns an integer
    int ans=INT_MIN; //initialize variable ans to the minimum integer value possible
    int sum=0; //initialize variable sum to 0 to store the sum of the current contiguous subarray
    for(auto i=v.begin();i!=v.end();i++){ //iterate over each element of the input vector v
        sum+=*i; //add the current element to the current sum
        ans=max(ans,sum); //update the maximum sum found so far
        if(sum<0){ //if the current sum becomes negative, reset it to 0
            sum=0;
        }
    }
    return ans; //return the maximum sum of any contiguous subarray in the input vector v
}
};
