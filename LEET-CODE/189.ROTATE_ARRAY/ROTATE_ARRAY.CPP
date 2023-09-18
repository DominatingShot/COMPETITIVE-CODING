#include <bits/stdc++.h> // Include standard C++ libraries
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size(); // Store the size of the vector
        k = k % n; // Reduce the value of k to the range [0, n-1] to handle cases where k is greater than n.
        vector<int> v(n, 0); // Define a vector to store the rotated elements with the same size as nums.
        
        // Copy the last k elements of nums to v (the rotated vector).
        v.assign(nums.end() - k, nums.end());
        
        // Append the first n-k elements of nums to v.
        v.insert(v.end(), nums.begin(), nums.end() - k);
        
        nums = v; // Assign the rotated vector back to the original nums vector to update it.
    }
};
