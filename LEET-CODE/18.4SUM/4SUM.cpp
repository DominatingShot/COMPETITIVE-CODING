class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) {
            return {}; // If there are fewer than 4 elements, there can be no quadruplets.
        }
        sort(nums.begin(), nums.end()); // Sort the input array in non-decreasing order.
        vector<int> temp; // A temporary vector to store one possible quadruplet.
        vector<vector<int>> res; // A vector to store the resulting quadruplets.
        helper(nums, target, 0, res, temp, 4); // Call the helper function to find quadruplets.
        return res;
    }

    void helper(vector<int>& nums, long long target, int start, vector<vector<int>>& res, vector<int>& temp, int numneed) {
        if (numneed != 2) {
            for (int i = start; i < nums.size() - numneed + 1; i++) {
                if (i > start && nums[i] == nums[i - 1]) {
                    continue; // Skip duplicate elements to avoid duplicate quadruplets.
                }
                temp.push_back(nums[i]);
                helper(nums, target - nums[i], i + 1, res, temp, numneed - 1);
                temp.pop_back();
            }
            return;
        }
        int l = start;
        int r = nums.size() - 1;
        while (l < r) {
            if (nums[l] + nums[r] < target) {
                l++;
            } else if (nums[l] + nums[r] > target) {
                r--;
            } else {
                temp.push_back(nums[l]);
                temp.push_back(nums[r);
                res.push_back(temp); // Found a quadruplet, add it to the result.
                temp.pop_back();
                temp.pop_back();
                l++;
                while (l < r && nums[l] == nums[l - 1]) {
                    l++; // Skip duplicate elements to avoid duplicate quadruplets.
                }
            }
        }
    }
};
