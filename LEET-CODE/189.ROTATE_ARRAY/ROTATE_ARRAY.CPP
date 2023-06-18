#include <bits/stdc++.h> //include standard C++ libraries
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size(); //store the size of the vector
        k = k%n; //reduce the value of k to the range [0, n-1]
        vector<int> v(n, 0); //define a vector to store the rotated elements
        v.assign(nums.end()-k, nums.end()); //assign the last k elements of the vector to the rotated vector
        v.insert(v.end(), nums.begin(), nums.end()-k); //insert the first n-k elements of the vector to the rotated vector
        nums = v; //assign the rotated vector to the original vector
        
    }
};