class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3;  // Vector to store the merged sorted array
        auto it1 = nums1.begin();  // Iterator for nums1
        auto it2 = nums2.begin();  // Iterator for nums2
        
        // Merge the two sorted arrays into nums3
        while (it1 != nums1.end() && it2 != nums2.end()) {
            if (*it1 < *it2) {
                nums3.push_back(*it1);
                it1++;
            } else {
                nums3.push_back(*it2);
                it2++;
            }
        }
        
        // Add remaining elements from nums1, if any
        while (it1 != nums1.end()) {
            nums3.push_back(*it1);
            it1++;
        }
        
        // Add remaining elements from nums2, if any
        while (it2 != nums2.end()) {
            nums3.push_back(*it2);
            it2++;
        }
        
        int n = nums3.size();
        
        if (n % 2 == 0) {
            // If the merged array has even length, calculate the average of the two middle elements
            return (nums3[n/2] + nums3[n/2 - 1]) / 2.0;
        } else {
            // If the merged array has odd length, return the middle element
            return nums3[n/2];
        }
    }
};
