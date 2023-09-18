class Solution {
public:
    void recursion(vector<int> num, int i, vector<vector<int>>& res) {
        if (i == num.size() - 1) {
            res.push_back(num); // If 'i' reaches the last element, add the current permutation to 'res'.
            return;
        }
        for (int k = i; k < num.size(); k++) {
            if (i != k && num[i] == num[k]) continue; // Skip duplicate elements.
            swap(num[i], num[k]); // Swap elements to generate permutations.
            recursion(num, i + 1, res); // Recursively generate permutations for the remaining elements.
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& num) {
        sort(num.begin(), num.end()); // Sort the input vector to handle duplicates.
        vector<vector<int>> res;
        recursion(num, 0, res); // Start the permutation generation from the first element (index 0).
        return res; // Return the vector of unique permutations.
    }
};
