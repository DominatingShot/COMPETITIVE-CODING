#include <bits/stdc++.h> // Include standard C++ libraries
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // The function removes all occurrences of 'val' from the 'nums' vector
        // and returns the size of the modified 'nums' vector.

        // The remove-erase idiom is used to remove the specified value from the vector.
        // It rearranges the elements, moving all instances of 'val' to the end of the vector.
        // The 'remove' function returns an iterator pointing to the new end of the vector.
        nums.erase(remove(nums.begin(), nums.end(), val), nums.end());

        // Return the size of the modified 'nums' vector.
        return nums.size();
    }
};
