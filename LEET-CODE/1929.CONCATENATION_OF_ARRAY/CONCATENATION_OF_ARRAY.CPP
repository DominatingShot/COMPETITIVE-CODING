class Solution {
public:
    vector<int> getConcatenation(vector<int>& v) {
        v.insert(v.end(), v.begin(), v.end()); // Concatenate the vector with itself

        // The insert function takes three arguments: insert(position, first, last)
        // v.end() represents the position at the end of the vector
        // v.begin() represents the starting position of the elements to be inserted
        // v.end() represents the ending position of the elements to be inserted
        // By specifying v.begin() to v.end(), we are inserting all elements from the beginning to the end of the vector at its end

        return v; // Return the concatenated vector
    }
};
