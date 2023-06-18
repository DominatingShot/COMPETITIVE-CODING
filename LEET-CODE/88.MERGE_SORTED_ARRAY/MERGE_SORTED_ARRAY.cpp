class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Initialize iterators for nums1 and nums2
        auto x = nums1.begin(); // Iterator for nums1
        auto y = nums2.begin(); // Iterator for nums2

        // Remove excess elements from nums1 and nums2
        nums1.erase(x + m, nums1.end()); // Erase elements in nums1 after the mth position
        nums2.erase(y + n, nums2.end()); // Erase elements in nums2 after the nth position

        // Create a new vector to store the merged result
        vector<int> merged;

        // Merge the elements from nums1 and nums2 in sorted order
        while (x != nums1.end() && y != nums2.end()) {
            if (*x < *y) {
                merged.push_back(*x); // Append the current element from nums1 to merged
                x++; // Move the iterator for nums1 to the next position
            }
            else {
                merged.push_back(*y); // Append the current element from nums2 to merged
                y++; // Move the iterator for nums2 to the next position
            }
        }
        // Append any remaining elements from nums1
        while (x != nums1.end()) {
            merged.push_back(*x); // Append the remaining elements from nums1 to merged
            x++; // Move the iterator for nums1 to the next position
        }

        // Append any remaining elements from nums2
        while (y != nums2.end()) {
            merged.push_back(*y); // Append the remaining elements from nums2 to merged
            y++; // Move the iterator for nums2 to the next position
        }

        // Assign the merged vector back to nums1
        nums1 = merged; // Update nums1 with the merged vector
    }
};
