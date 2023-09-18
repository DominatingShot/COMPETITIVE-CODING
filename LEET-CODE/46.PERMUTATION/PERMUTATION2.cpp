class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // Base case: If there's only one element in the vector, return it as a single-element permutation.
        if (nums.size() == 1) {
            return {nums};
        }
        
        vector<vector<int>> ans; // Create a vector to store permutations.
        
        for (int i = 0; i < nums.size(); i++) {
            int n = nums.front(); // Get the first element.
            nums.erase(nums.begin(), nums.begin() + 1); // Remove the first element from the vector.
            
            // Recursively generate permutations for the remaining elements.
            vector<vector<int>> temp = permute(nums);
            
            for (int j = 0; j < temp.size(); j++) {
                temp[j].push_back(n); // Append the first element to each permutation.
                ans.push_back(temp[j]); // Add the updated permutation to the result.
            }
            
            nums.push_back(n); // Restore the removed element to its original position.
        }
        
        return ans; // Return the vector of permutations.
    }
};
