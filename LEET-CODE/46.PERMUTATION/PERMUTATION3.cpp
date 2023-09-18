class Solution {
public:
    void recursion(vector<int> num, int i, vector<vector<int> > &res) {
        // If the current index 'i' reaches the last element, it means we have a complete permutation.
        if (i == num.size() - 1) {
            res.push_back(num); // Add the permutation to the result vector.
            return;
        }
        
        // Iterate through the remaining elements starting from index 'i'.
        for (int k = i; k < num.size(); k++) {
            swap(num[i], num[k]); // Swap the elements at indices 'i' and 'k'.
            recursion(num, i + 1, res); // Recursively generate permutations for the remaining elements.
            swap(num[i], num[k]); // Restore the original order by swapping back.
        }
    }
    
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > res; // Vector to store permutations.
        recursion(num, 0, res); // Start the recursion with index '0'.
        return res; // Return the vector of permutations.
    }
};
