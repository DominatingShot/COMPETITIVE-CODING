class Solution {
public:
    // Recursive function to generate permutations
    void permuteRec(vector<int>& nums, int begin, vector<vector<int>>& result) { 
        if (begin == nums.size()) { 
            result.push_back(nums); // If we've reached the end of the vector, add the current permutation to the result.
            return; 
        } 
        for (int i = begin; i < nums.size(); i++) { 
            swap(nums[begin], nums[i]); // Swap the current element with the elements after it.
            permuteRec(nums, begin + 1, result); // Recursively generate permutations for the remaining elements.
            swap(nums[begin], nums[i]); // Undo the previous swap to backtrack and explore other permutations.
        } 
    } 
                                                                                                   
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result; // Initialize a vector to store the permutations.
        permuteRec(nums, 0, result); // Start generating permutations from the beginning of the vector.
        return result; // Return the vector containing all permutations.
    }
};
