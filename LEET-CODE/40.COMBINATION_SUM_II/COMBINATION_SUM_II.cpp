class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;  // Store the final result, which will be unique combinations that sum up to the target.
        vector<int> t;  // Temporary vector to store a single combination.
        sort(candidates.begin(), candidates.end());  // Sort the candidates in ascending order to handle duplicates.

        // Start the recursive process to find combinations.
        combinationSumRec(candidates, target, 0, result, t);

        return result;  // Return the list of unique combinations.
    }

    // Recursive function to find combinations.
    void combinationSumRec(vector<int>& candidates, int target, int begin, vector<vector<int>>& result, vector<int>& t) {
        if (target == 0) {  // If the target sum is reached, add the current combination to the result.
            result.push_back(t);
            return;
        }

        int x = begin;  // Store the current position in the candidates array.

        while (begin < candidates.size() && target - candidates[begin] >= 0) {
            // Check for duplicates and skip them to avoid duplicate combinations.
            if (begin > x && candidates[begin] == candidates[begin - 1]) {
                begin++;
                continue;
            }

            t.push_back(candidates[begin]);  // Add the current candidate to the combination.
            
            // Recursively call with the updated target and move to the next candidate.
            combinationSumRec(candidates, target - candidates[begin], begin + 1, result, t);
            
            t.pop_back();  // Remove the last added candidate to backtrack and explore other combinations.
            begin++;  // Move to the next candidate.
        }
    }
};
