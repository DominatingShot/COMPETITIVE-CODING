#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> s;  // Set to store unique values
        if (k == 0) return false;  // If k is 0, there are no nearby elements to compare
        for (int i = 0; i < nums.size(); i++) {
            long long val = nums[i];  // Current value
            if (!s.empty()) {
                if (s.size() == k + 1)
                    s.erase(nums[i - k - 1]);  // Remove the element outside the window
                auto higher = s.lower_bound(val);  // Find the smallest element bigger or equal to val
                if (higher != s.end() && (*higher - val <= t))
                    return true;  // If the difference between higher and val is less than or equal to t, return true
                if (higher != s.begin()) {
                    higher--;  // Move higher pointer to the biggest element smaller than val
                    auto low = higher;  // Create a low pointer
                    if (low != s.end() && ((val - *low) <= t))
                        return true;  // If the difference between val and low is less than or equal to t, return true
                }
            }
            s.insert(val);  // Insert current value into the set
        }
        return false;  // No nearby elements found satisfying the conditions
    }
};
