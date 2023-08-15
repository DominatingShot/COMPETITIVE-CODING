class Solution {
public:
    int longestConsecutive(vector<int>& v) {
        if (v.size() < 2) {
            return v.size(); // If the vector has fewer than 2 elements, return its size as the longest consecutive sequence length.
        }
        sort(v.begin(), v.end()); // Sort the vector in ascending order.
        int longest = 1; // Initialize the length of the longest consecutive sequence.
        int cur = 1; // Initialize the length of the current consecutive sequence.
        for (auto i = v.begin(); i != v.end() - 1; i++) {
            if (*i == *(i + 1)) {
                continue; // Skip duplicates.
            }
            if (*i + 1 == *(i + 1)) {
                cur = cur + 1; // If the current element and the next element are consecutive, increment the current sequence length.
            } else {
                longest = max(cur, longest); // Update the longest sequence length with the maximum of current and previous longest.
                cur = 1; // Reset the current sequence length.
            }
        }
        return max(cur, longest); // Return the maximum of the last current sequence length and the overall longest length.
    }
};
