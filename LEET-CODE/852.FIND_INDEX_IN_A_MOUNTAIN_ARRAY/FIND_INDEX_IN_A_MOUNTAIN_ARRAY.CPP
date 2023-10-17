class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        if (arr.size() == 3) { // Handle the special case of an array with three elements.
            return 1; // The peak in this case is always the middle element.
        }
        int left = 0; // Initialize the left pointer to 0.
        int right = arr.size() - 1; // Initialize the right pointer to the last index.

        while (left < right) { // Perform a binary search until left and right pointers meet.
            int mid = left + (right - left) / 2; // Calculate the mid-point to examine.

            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                return mid; // If arr[mid] is greater than its neighbors, it's a peak. Return its index.
            } else if (arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1]) {
                left = mid; // If arr[mid] is greater than the left neighbor but less than the right neighbor, move the left pointer to mid.
            } else if (arr[mid] < arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                right = mid; // If arr[mid] is greater than the right neighbor but less than the left neighbor, move the right pointer to mid.
            }
        }
    }
};
