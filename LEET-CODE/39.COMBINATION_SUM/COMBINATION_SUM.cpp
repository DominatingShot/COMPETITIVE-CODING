class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result; // Create a vector to store the combinations.
        vector<int> t; // Create a vector 't' to store the current combination.
        
        combinationSumRec(candidates, target, 0, result, t); // Call the recursive function to find combinations.
        
        return result; // Return the vector containing all combinations.
    }
    
    // Recursive function to find combinations.
    void combinationSumRec(vector<int>& candidates, int target, int begin, vector<vector<int>>& result, vector<int>& t) {
        if (target == 0) { // If the target is reached, add the current combination to the result.
            result.push_back(t);
            return;
        }
        
        while (begin < candidates.size() && target - candidates[begin] >= 0) {
            t.push_back(candidates[begin]); // Add the current candidate to the combination.
            combinationSumRec(candidates, target - candidates[begin], begin, result, t); // Recursively find combinations with the reduced target.
            begin++; // Move to the next candidate.
            t.pop_back(); // Backtrack by removing the last added candidate for exploring other combinations.
        }
    }
};
